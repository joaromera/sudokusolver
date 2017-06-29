#include <iostream>
#include "sudoku.cpp"

#ifndef SUDOKU_H_
#define SUDOKU_H_

// Board definition
typedef int Board[9][9];

// Returns where cell in position f c is empty
bool isEmptyCell(Board t, int f, int c);

// Empties the board
void emptyBoard(Board t);

// Returns the amount of empty cells
int nmbrEmptyCells(Board t);

// Returns the value for the row of the first empty cell
int firstEmptyCellRow(Board t);

// Returns the value for the row of the first empty cell
int firstEmptyCellColumn(Board t);

// If value at cell f c is not 0 it returns the value
int cellValue(Board t, int f, int c);

// Changes the value at f c
void changeValue(Board t, int f, int c, int v);

// Empties the value at cell fc
void emptyCell(Board t, int f, int c);

// Tells if the board is a 9x9 matrix and all of it's values range from 0 to 9
bool isValidBoard(Board t);

// Tells if input is a valid board, and there are no repetitions in rows, columns and regions
bool isPartiallySolved(Board t);

// Returns if the board is solved (partially solved and no empty cells)
bool isTotallySolved(Board t);

// Returns if one board is a sub board of the other (every cell different from 0 has the same value)
bool subBoard(Board t0, Board t1);

// Input is a valid board, returns true if the board can be solved and modifies it.
// If can't be solved returns false and leaves the board unchanged.
bool hasSolution(Board t);

// Solves the board
bool solve(Board t);

// Prints the board
void sudoku_print(Board t);

// Counts number of repetitions
int repetitions(int l[]);

// Copies the board
void copyBoard(Board t, Board s);

// Recursive helper function for solving the board
bool solving(Board t);

#endif /* SUDOKU_H_ */
