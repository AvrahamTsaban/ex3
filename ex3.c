/******************
Name:Avraham Tsaban
ID: 207088733
Assignment: 3
*******************/


#include <stdio.h>

#ifndef ROWS
#define ROWS 6
#endif

#ifndef COLS
#define COLS 7
#endif

#define VECTOR_LEN 2

#ifndef CONNECT_N
#define CONNECT_N 4
#endif

/* Tokens */
#define EMPTY '.'
#define TOKEN_P1 'X'
#define TOKEN_P2 'O'

#define HUMAN 1
#define COMPUTER 2

/* Logics */
#define TRUE 1
#define FALSE 0
#define FAILURE -1

int getPlayerType(int);
void initBoard(char[][COLS], int, int);
void printBoard(char[][COLS], int, int);
void runConnectFour(char[][COLS], int, int, int, int);
int makeMove(char[][COLS], int, int, char);
int isInBounds(int, int);
int getFreeRow(char[][COLS], int, int);
int humanChoice(char board[][COLS], int);
int humanInput(int);
int computerChoose(char[][COLS], int, int, char);
void setPriority(int[], int);
int lineLength(char[][COLS], int, int, int, int, char);
int isColumnFull(char[][COLS],  int);
int isBoardFull(char[][COLS], int);

int main() {
    // main function initializes the game board, gets player types, and starts the game loop.
    char board[ROWS][COLS];
    printf("Connect Four (%d rows x %d cols)\n\n", ROWS, COLS);
    int p1Type = getPlayerType(1);
    int p2Type = getPlayerType(2);
    initBoard(board, ROWS, COLS);
    printBoard(board, ROWS, COLS);
    runConnectFour(board, ROWS, COLS, p1Type, p2Type);
    return TRUE;
}

void initBoard(char board[][COLS], int rows, int cols) {
    // initializes every single cell in the board to EMPTY.
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            board[r][c] = EMPTY;
        }
    }
}

void printBoard(char board[][COLS], int rows, int cols) {
    // prints the current state of the board to the console.
    printf("\n");
    for (int r = 0; r < rows; r++) {
        printf("|");
        for (int c = 0; c < cols; c++) {
            putchar(board[r][c]);
            printf("|");
        }
        printf("\n");
    }
    for (int c = 1; c <= cols; c++) {
        printf(" %d", c % 10);
    }
    printf("\n\n");
}

int getPlayerType(int playerNumber) {
    // prompts the user to select player type (human or computer) for the given player number.
    char ch;
    while (TRUE) {
        printf("Choose type for player %d: h - human, c - computer: ", playerNumber);
        int n = scanf(" %c", &ch);
        // validate input
        if (n != TRUE) {
            printf("Input error. Try again.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        // parse input and return corresponding type
        if (ch == 'h' || ch == 'H') return HUMAN;
        if (ch == 'c' || ch == 'C') return COMPUTER;

        printf("Invalid selection. Enter h or c.\n");
        while (getchar() != '\n'); // clear rest of input
    }
}

void runConnectFour(char board[][COLS], int rows, int cols, int p1Type, int p2Type) {
    // main game loop. alternates turns between players until win or tie.
    int currentPlayer = 1;
    int column, row;
    char token, isHuman;
    // infinite game loop until win or tie
    while (TRUE){
        // determine current player's token and type
        if (currentPlayer == 1) {
            token = TOKEN_P1;
            isHuman = (p1Type == HUMAN);
        } else {
            token = TOKEN_P2;
            isHuman = (p2Type == HUMAN);
        }
        // announce current player's turn and get column choice
        printf("Player %d (%c) turn.\n", currentPlayer, token);
        if (isHuman) {
            // prompts the user to choose column input
            column = humanChoice(board, cols);
        } else {
            // computer chooses column based on strategy defined in computerChoose
            column = computerChoose(board, rows, cols, token);
            printf("Computer chose column %d\n",column + 1);    
        }
        // make the move and get the row where the token was placed
        row = makeMove(board, rows, column, token);
        printBoard(board, rows, cols);
        // check for win or tie and announce result if so
        if (lineLength(board, rows, cols, row, column, token) >= CONNECT_N) {
            printf("Player %d (%c) wins!\n", currentPlayer, token);
            return;
        }
        if (isBoardFull(board, cols)) {
            printf("Board full and no winner. It's a tie!\n");
            return;
        }
        // swap players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}

int makeMove(char board[][COLS], int rows, int column, char token) {
    /* looks for the lowest free row in the specified column and places the token there.
    returns the index of the row where the token was placed. if the column is full, returns FAILURE (-1).
    assumes column is in bounds, used after validation */
    int freeRow = getFreeRow(board, rows, column);
    if (freeRow != FAILURE) {
        board[freeRow][column] = token;
    }
    return freeRow;    
}

int getFreeRow(char board[][COLS], int rows, int column) {
    /* looks for the lowest free row in the specified column. returns the index of that row.
    if the column is full, returns FAILURE (-1).
    assumes column is in bounds, used after validation */
    for (int r = rows - 1; r >= 0; r--) {
        if (board[r][column] == EMPTY) {
            return r;
        }
    }
    return FAILURE;
}

int isColumnFull(char board[][COLS], int column) {
    /* stripped down version of getFreeRow. 
    tailored for determining if the specified column is full, by checking the topmost row.
    returns TRUE (1) if full, FALSE (0) otherwise.
    assumes column is in bounds, used after validation */
    return board[0][column] != EMPTY;
}

int isBoardFull(char board[][COLS], int cols) {
    /* Checks if the entire board is full by checking each column.
    Returns TRUE (1) if full, FALSE (0) otherwise. */
    for (int column = 0; column < cols; column++) {
        if (isColumnFull(board, column) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

int lineLength(char board[][COLS], int rows, int cols, int row, int column, char token) {
    /* Given the last placed token at (row, column), 
    checks in all 4 directions (horizontal, vertical, two diagonals) 
    for the longest line of consecutive tokens of the same type as 'token'. 
    Returns the length of the longest line found. */
    // define direction vectors for right, down-right, down, down-left as an array of (y,x) pairs
    const int directions[][VECTOR_LEN] = {{0,1},{1,1},{1,0},{1,-1}};
    // define constants for direction processing
    const int directionsNum = 4;
    const int yAxis = 0;
    const int xAxis = 1;
    // initialize maxLength to 1 (the placed token itself)
    int maxLength = 1;
    for (int axis = 0; axis < directionsNum; axis++) {
        // for each direction, check both forward and backward
        int length = 1;
        int downwards = directions[axis][yAxis];
        int rightwards = directions[axis][xAxis];
        // this loop checks in one direction until out of bounds or token mismatch
        for (int i = 1; i < CONNECT_N; i++) {
            int checkRow = row + (i * downwards);
            int checkCol = column + (i * rightwards);
            // check bounds for both row and column before accessing board
            if (checkRow >= rows || checkRow < 0 || checkCol >= cols || checkCol < 0) {
                break;
            }
            // check if token matches
            if (board[checkRow][checkCol] == token) {
                ++length;
            } else {
                // token mismatch, break out of this direction check
                break;
            }
        }
        // reverse direction to check the opposite side
        downwards *= -1;
        rightwards *= -1;
        for (int i = 1; i < CONNECT_N; i++) {
            int checkRow = row + (i * downwards);
            int checkCol = column + (i * rightwards);
            // check bounds for both row and column before accessing board
            if (checkRow >= rows || checkRow < 0 || checkCol >= cols ||     checkCol < 0) {
                break;
            }
            // check if token matches
            if (board[checkRow][checkCol] == token) {
                ++length;
            } else {
                // token mismatch, break out of this direction check
                break;
            }
        }
        // if length found is greater than or equal to CONNECT_N, 
        // return immediately to declare victory (or potential victory)
        if (length >= CONNECT_N) {
            return length;
        }
        // update maxLength if current length is greater
        if (maxLength < length) {
            maxLength = length;
        }
        // proceed to next direction
    }
    return maxLength;
}

int humanChoice(char board[][COLS], int cols) {
    /* Prompts the human player to enter a valid column number (0-based) that is not full.
    Prompts error messages for invalid input, and repeats until a valid column is chosen. 
    Returns the chosen column index (0-based). */
    int column;
    while (TRUE) {
        int choose = humanInput(cols);
        column = choose - 1; // convert to 0-based index
        // "column" represents backend index, choose represents UI index
        if (isInBounds(cols, column) == FALSE) {
            printf("Invalid column. Choose between 1 and %d.\n", cols);
            continue;
        }
        if (isColumnFull(board, column)) {
        // may only be called after isInBounds
            printf("Column %d is full. Choose another column.\n", choose);
            continue;
        }
        break;
    }
    return column;
}

int humanInput(int cols) {
    /* Prompts the human player to enter a column number between 1 and cols (inclusive).
    Validates the input to ensure it is a number. Repeats the prompt until a valid number is entered.
    Returns the chosen column number as an integer.
    Return value is not validated for bounds yet. */
    while (TRUE) {
        // prompt user for input
        printf("Enter column (1-%d): ", cols);
        int choose, check;
        check = scanf("%d", &choose);
        // validate input is a number, else clear input buffer and reprompt
        if (check != TRUE) {
            printf("Invalid input. Enter a number.\n");
            while (getchar() != '\n') {
                continue;
            }
            continue;
        }
        // In case of proper input, clear rest of input buffer and return value
        while (getchar() != '\n') {
            continue;
        }
        return choose;
    }

}

int isInBounds(int cols, int column) {
    /* validates input column is in bounds. returns TRUE (1) if row is in bounds, FALSE (0) otherwise */
    return (column < cols && column >= 0);
}

int computerChoose(char board[][COLS], int rows, int cols, char token) {
    /* Chooses a column for the computer player to make a move based on a priority strategy.
    The strategy is as follows:
    1. Check for a winning move for the computer player.
    2. Check for a winning move for the rival player and block it.
    3. Check for moves that create a potential winning line (CONNECT_N - 1) for the computer player.
    4. Check for moves that create a potential winning line for the rival player and block it.
    5. If no strategic moves are found, choose the first available column based on priority.
    Returns the chosen column index (0-based).
    Possible improvement:
    1. avoid allowing rival to achieve victory, from stage 3 on.
    2. Initialize static priority array on first call, so that ubsequent calls will reuse the same array. Example:
    static int priority[COLS] = {0};
    if (priority[0] == 0 && cols > 1) {
        setPriority(priority, cols);
    }
    Would save time on repeated calls; impossible for coding consistency requirements (Coding Style document).*/
    // Initialize priority array
    int priority[COLS] = {0};
    setPriority(priority, cols);
        // Iterate through priority array to find the first winning move
    for (int column = 0; column < cols; column++) {
        int row = getFreeRow(board, rows, priority[column]);
        if (row == FAILURE) {
            continue;
        }
        int potential = lineLength(board, rows, cols, row, priority[column], token);
        if (potential >= CONNECT_N) {
            return priority[column];
        }
    }
    // Determine rival token
    char rival = (token == TOKEN_P1) ? TOKEN_P2 : TOKEN_P1;
    // Iterate through priority array to find the first winning move for rival and block it
    for (int column = 0; column < cols; column++) {
        int row = getFreeRow(board, rows, priority[column]);
        if (row == FAILURE) {
            continue;
        }
        int potential = lineLength(board, rows, cols, row, priority[column], rival);
        if (potential >= CONNECT_N) {
            return priority[column];
        }
    }
    // Iterate through priority array to find the first potential winning move
    for (int column = 0; column < cols; column++) {
        int row = getFreeRow(board, rows, priority[column]);
        if (row == FAILURE) {
            continue;
        }
        int potential = lineLength(board, rows, cols, row, priority[column], token);
        if (potential >= CONNECT_N - 1) {
            return priority[column];
        }
    }
    // Iterate through priority array to find the first potential winning move for rival and block it
    for (int column = 0; column < cols; column++) {
        int row = getFreeRow(board, rows, priority[column]);
        if (row == FAILURE) {
            continue;
        }
        int potential = lineLength(board, rows, cols, row, priority[column], rival);
        if (potential >= CONNECT_N - 1) {
            return priority[column];
        }
    }
    // If no strategic moves found, choose the first available column based on priority
    for (int column = 0; column < cols; column++) {
        int row = getFreeRow(board, rows, priority[column]);
        if (row == FAILURE) {
            continue;
        }
        return priority[column];
    }
    // If all columns are full (should not happen in normal gameplay), return FAILURE (-1)
    return FAILURE;
}

void setPriority(int priority[], int cols) {
    /* Sets the priority array for column selection by the computer player.
    The middle column has the highest priority,followed by columns adjacent to the middle, moving outward.
    Out of every two columns at the same distance from the middle, the left one is prioritized first. */
    // determine middle column and if number of columns is odd
    int middleColumn = cols / 2;
    int isLengthOdd = cols % 2;
    int index, leftMiddle;
    // set middle column(s) and insert them into priority array, then assign index to next free position
    if (isLengthOdd) {
        leftMiddle = middleColumn;
        priority[0] = middleColumn;
        index = 1;
    } else {
        leftMiddle = middleColumn - 1;
        priority[0] = leftMiddle;
        priority[1] = middleColumn;
        index = 2;
    }
    /* add pairs of columns on either side of the middle column, moving outward.
    index advances to next free position after each insertion */
    for (int distance = 1; distance <= leftMiddle; distance++) {
        priority[index++] = leftMiddle - distance;
        priority[index++] = middleColumn + distance;
    }
    return;
}
