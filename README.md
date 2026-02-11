The doc: https://docs.google.com/document/d/1XuCF9WUz8-6libxW4x2agrnJtV9_YrDDJ7YEYV4Zmpc/edit?tab=t.0

/***********************************************************
 * CONNECT FOUR - C IMPLEMENTATION SUMMARY
 * GAME CORE: AVRAHAM TSABAN (ID: 207088733)
 * SUMMARY REV: 1.0 (2025-11-30)
 ***********************************************************/

## Quick start
- Build: `gcc -std=c99 -Wall -Wextra -Werror -DNDEBUG -DROWS=6 -DCOLS=7 ex3.c -o ex3.out -lm`
- Run: `./ex3.out`
- Input: type `h` / `c` to select player types, then enter column numbers (1-based).

## Tuning (compile-time)
- `ROWS` / `COLS` (defaults 6/7). Override at compile time, e.g.:
  - `gcc -std=c99 -Wall -Wextra -Werror -DNDEBUG -DROWS=8 -DCOLS=8 ex3.c -o ex3.out -lm`
- `CONNECT_N` (default 4)
- Tokens: `TOKEN_P1='X'`, `TOKEN_P2='O'`, empty `'.'`

## Files
- `ex3.c`: all gameplay logic (I/O, loop, AI, board ops).

## I/O contract
- Human input: columns 1..COLS; rejects out-of-bounds / full columns with a re-prompt.
- Board printout: grid with column indices modulo 10 on footer.

## AI priority (summary)
- Win
- Block win
- Create threat (N-1)
- Block threat (N-1)
- Fallback: center-first priority ordering via `setPriority`.

## Testing checklist
- Win detection: horizontal, vertical, both diagonals.
- Tie: full board with no winner.
- Bounds: reject columns <1 or >COLS.
- Full column handling: re-prompt.
- AI: confirm it blocks imminent wins and takes immediate wins.

# 1. PROGRAM OVERVIEW
# --------------------
# This program implements the classic Connect Four game (4-in-a-row)
# for a board of ROWS x COLS (default 6x7).
# Supports two player types: HUMAN ('h') and COMPUTER ('c').
# The game loop manages turns, move execution, and win/tie checks.

# 2. KEY FUNCTIONS AND CALL FLOW
# --------------------------------

# 2.1 ENTRY POINT & GAME CONTROL
# ------------------------------
# main()
#    - Initializes game state.
#    - Calls getPlayerType() for P1 and P2 setup.
#    - Calls initBoard() and printBoard().
#    - Starts runConnectFour().
#
# runConnectFour()
#    - Main game loop. Alternates turns until termination.
#    - CALLS: humanChoice() OR computerChoose() -> makeMove()
#    - CALLS: printBoard()
#    - CALLS: lineLength() (Checks for win)
#    - CALLS: isBoardFull() (Checks for tie)

# 2.2 MOVE EXECUTION
# ------------------
# makeMove(board, rows, col, token)
#    - Places 'token' in the lowest free row of 'col'.
#    - RELIES ON: getFreeRow() to find the placement slot.
#    - RETURNS: Row index of placement (or FAILURE).

# 2.3 WIN/TIE LOGIC
# -----------------
# lineLength(board, rows, cols, r, c, token)
#    - THE CORE LOGIC: Checks all 4 directions (H/V/D1/D2) from (r,c)
#      for the longest chain of 'token'.
#    - RETURNS: The maximum length found. If >= CONNECT_N (4), it's a win.
#
# isBoardFull(board, cols)
#    - Checks if ALL columns are full.
#    - RELIES ON: isColumnFull() (Checks board[0][col] != EMPTY).

# 3. PLAYER INTERACTION (I/O)
# -----------------------------
# getPlayerType(playerNum)
#    - PROMPT: Selects 'h' or 'c' for a player.
#
# humanChoice(board, cols)
#    - GETS: Valid column input from humanInput().
#    - VALIDATES: Checks isInBounds() and isColumnFull().
#
# computerChoose(board, rows, cols, token)
#    - **AI STRATEGY:** Determines optimal move by priority:
#      1. WIN (Self)
#      2. BLOCK (Rival)
#      3. THREAT (N-1 Self)
#      4. BLOCK THREAT (N-1 Rival)
#      5. PRIORITY (Center-first)
#    - RELIES ON: setPriority() for preferred column order.
#    - USES: getFreeRow() and lineLength() for move evaluation.

# 4. UTILITY FUNCTIONS
# --------------------
# initBoard(board, rows, cols)
#    - Fills the board with EMPTY ('.') token.
#
# printBoard(board, rows, cols)
#    - Outputs board state and column numbers (1-7).
#
# getFreeRow(board, rows, col)
#    - Finds the lowest available row index in 'col'.
#    - RETURNS: Row index or FAILURE (-1).
#
# isInBounds(cols, column)
#    - Basic validation for column index [0, COLS-1].
#
# setPriority(priority[], cols)
#    - Initializes the column search order for the AI (e.g., [3, 2, 4, 1, 5, 0, 6] for 7 cols).
