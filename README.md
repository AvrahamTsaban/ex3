The doc: https://docs.google.com/document/d/1XuCF9WUz8-6libxW4x2agrnJtV9_YrDDJ7YEYV4Zmpc/edit?tab=t.0

Function list and how they rely each other:

int main(): 
    initializes board
    calls getPlayerType, initBoard, printBoard, runConnectFour

int getPlayerType(int);
    only i\o and standard functions

void initBoard(char[][COLS], int, int);
    accesses board

void printBoard(char[][COLS], int, int);
    accesses board

void runConnectFour(char board[][COLS], int rows, int cols, int p1Type, int p2Type):
    accesses board
    calls humanChoose, computerChoose, makeMove, printBoard, checkVictory, isBoardFull

/* Human player: asks repeatedly until a valid non-full column is chosen (0-based) */
int humanChoose(char[][COLS], int, int);

/* Computer*/
int computerChoose(char[][COLS], int, int, char, char);

/* Place token in column (0-based). Return row index or -1 if illegal */
int makeMove(char[][COLS], int, int, int, char);

/* Return index of row where token will land, or -1 if column full */
int getFreeRow(char[][COLS], int, int, int);

int isColumnFull(char[][COLS], int, int, int);
    accesses board
    (implements a stripped-down version of getFreeRow)

int isBoardFull(char[][COLS], int, int);
    accesses board 
    calls isColumnFull

int isInBounds(int, int, int, int);


int checkVictory(char[][COLS], int, int, int, int, char);

