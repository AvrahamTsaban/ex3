#include <stdio.h>

#ifndef ROWS
#define ROWS 6
#endif

#ifndef COLS
#define COLS 7
#endif

#define CONNECT_N 4

/* Tokens */
#define EMPTY '.'
#define TOKEN_P1 'X'
#define TOKEN_P2 'O'

#define HUMAN 1
#define COMPUTER 2

int isColumnFull(char[][COLS], int, int, int);

int isBoardFull(char[][COLS], int, int);

int isInBounds(int, int, int, int);

/* Return index of row where token will land, or -1 if column full */
int getFreeRow(char[][COLS], int, int, int);

/* Place token in column (0-based). Return row index or -1 if illegal */
int makeMove(char[][COLS], int, int, int, char);

int checkVictory(char[][COLS], int, int, int, int, char);

/* Human player: asks repeatedly until a valid non-full column is chosen (0-based) */
int humanChoose(char[][COLS], int, int);

/* Computer*/
int computerChoose(char[][COLS], int, int, char, char);

void runConnectFour(char[][COLS], int, int, int, int);

void initBoard(char[][COLS], int, int);

void printBoard(char[][COLS], int, int);

int getPlayerType(int);


int main() {
    char board[ROWS][COLS];
    printf("Connect Four (%d rows x %d cols)\n\n", ROWS, COLS);
    int p1Type = getPlayerType(1);
    int p2Type = getPlayerType(2);
    initBoard(board, ROWS, COLS);
    printBoard(board, ROWS, COLS);
    runConnectFour(board, ROWS, COLS, p1Type, p2Type);
    return 0;
}

void initBoard(char board[][COLS], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            board[r][c] = EMPTY;
        }
    }
}

void printBoard(char board[][COLS], int rows, int cols) {
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
    char ch;
    while (1) {
        printf("Choose type for player %d: h - human, c - computer: ", playerNumber);
        int n = scanf(" %c", &ch);
        if (n != 1) {
            printf("Input error. Try again.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        if (ch == 'h' || ch == 'H') return HUMAN;
        if (ch == 'c' || ch == 'C') return COMPUTER;

        printf("Invalid selection. Enter h or c.\n");
        while (getchar() != '\n'); // clear rest of input
    }
}

void runConnectFour(char board[][COLS], int rows, int cols, int p1Type, int p2Type) {
    int currentPlayer = 1;
    int column;
    char token, isVictorious, isHuman;
    while (1){
        if (currentPlayer = 1)
        {
            token = TOKEN_P1;
            isHuman = (p1Type == HUMAN);
        }
        else
        {
            token = TOKEN_P2;
            isHuman = (p2Type == HUMAN);
        }
        printf("Player %d (%c) turn.\n", currentPlayer, token);
        if (isHuman) {
                printf("Enter column (1-%d):", cols);
                column = humanChoose(board, rows, cols);
            }
            else {
                // column = computerChoose(board, rows, cols, char, char);
                // check if computer needs validation of column
            }
        makeMove(board, rows, cols, column, token);
        printBoard(board, rows, cols);

        // actually, checkVictory may be called inside if, and not provide winner variable, since the winner is the current player
        /*if (checkVictory(char[][COLS], int, int, int, int, char) {
            printf("Player %d (%c) wins!\n", currentPlayer, token);
            break;
        }*/
        if (isBoardFull(board, rows, cols)) {
            printf("Board full and no winner. It's a tie!\n");
            break;
        }

        // swap players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

}

int makeMove(char board[][COLS], int rows, int cols, int column, char token) {
    int freeRow = getFreeRow(board, rows, cols, column);
    if (freeRow != -1) {
        board[freeRow][column] = token;
    }
    return freeRow;    
}

int getFreeRow(char board[][COLS], int rows, int cols, int column) {
    for (int r = rows - 1; r >= 0; r--) {
        if (board[r][column] == EMPTY) {
            return r;
        }
    }
    return -1;
}

int isColumnFull(char board[][COLS], int rows, int cols, int column) {
    return board[rows-1][column] != EMPTY;
}

int isBoardFull(char board[][COLS], int rows, int cols) {
    for (int column = 0; column < cols; column++) {
        if (isColumnFull(board, rows, cols, column) == 0) {
            return 0;
        }
    }
    return 1;
}