# Exercise 3 — Connect Four

## Overview

A Connect Four game implemented in C, supporting configurable board dimensions via compile-time flags. The game allows any combination of human and computer players, with an AI that uses a priority-based strategy (win → block → threaten → block threat → center preference).

## Author

Avraham Tsaban

## Compilation

```bash
gcc -std=c99 -Wall -Wextra -Werror -DNDEBUG -DROWS=6 -DCOLS=7 ex3.c -o ex3.out -lm
```

Board dimensions can be changed at compile time, e.g.:

```bash
gcc -std=c99 -Wall -Wextra -Werror -DNDEBUG -DROWS=8 -DCOLS=8 ex3.c -o ex3.out -lm
```

## Running

```bash
./ex3.out
```

Select player types (`h` for human, `c` for computer), then enter column numbers (1-based) for human moves.

## Features

- Configurable board dimensions (`ROWS`/`COLS`) and win sequence length (`CONNECT_N`, default 4)
- Human input validation (out-of-bounds, full columns, non-numeric input)
- Win detection in all four directions (horizontal, vertical, both diagonals)
- Tie detection when the board is full
- Computer AI with center-first priority ordering

## Code Structure

All code resides in a single file `ex3.c`. Board dimensions and win length are compile-time constants (`ROWS`, `COLS`, `CONNECT_N`).

### Entry Point and Game Control

| Function | Description |
|----------|-------------|
| `main()` | Initializes board, gets player types, starts game loop. *(TA-provided)* |
| `runConnectFour(board, rows, cols, p1Type, p2Type)` | Main game loop — alternates turns, calls move functions, checks win/tie. |

### Board Operations

| Function | Description |
|----------|-------------|
| `initBoard(board, rows, cols)` | Fills all cells with `EMPTY` (`.`). |
| `printBoard(board, rows, cols)` | Prints the board grid with column indices. *(TA-provided)* |
| `makeMove(board, rows, column, token)` | Places token in the lowest free row of `column`. Returns row index or `FAILURE`. |
| `getFreeRow(board, rows, column)` | Finds the lowest empty row in a column. |

### Player Input

| Function | Description |
|----------|-------------|
| `getPlayerType(playerNum)` | Prompts for `h`/`c` selection, returns `HUMAN` or `COMPUTER`. *(TA-provided)* |
| `humanChoice(board, cols)` | Gets a valid column from the human player (validates bounds and fullness). |
| `humanInput(cols)` | Reads and validates numeric input; clears buffer on non-numeric entries. |

### Win and Tie Detection

| Function | Description |
|----------|-------------|
| `lineLength(board, rows, cols, row, col, token)` | Checks all 4 directions (H/V/D1/D2) from `(row, col)` for the longest chain of `token`. |
| `isColumnFull(board, column)` | Returns `TRUE` if the top cell of `column` is occupied. |
| `isBoardFull(board, cols)` | Returns `TRUE` if all columns are full. |
| `isInBounds(cols, column)` | Validates column index is within `[0, cols)`. |

### Computer AI

| Function | Description |
|----------|-------------|
| `computerChoose(board, rows, cols, token)` | Selects a column by priority: win → block win → create (N−1) → block (N−1) → center-first fallback. |
| `setPriority(priority[], cols)` | Fills array with column indices ordered from center outward (left-first for ties). |

## Project Files

| File | Description |
|------|-------------|
| `ex3.c` | Source code |
| `ex3.example` | Reference Linux executable provided by the TA |
| `ex3_instructions.md` | Exercise instructions |
| `examples/` | Sample output files for various board sizes (provided by the TA) |

## Attribution

The exercise design, specifications, and instructions were created by **Eyal Dayan**, the Teaching Assistant responsible for this assignment. The instructions file (`ex3_instructions.md`), the reference executable (`ex3.example`), and the sample outputs in `examples/` are his work. The functions `main`, `printBoard`, and `getPlayerType` in the source code were also provided by the TA. Any license in this repository applies only to the student's code implementation.
