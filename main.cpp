#include <iostream>
#include "sudoku.h"

// Functions in sudoku.cpp descriptions of them in sudoku.h

int main(int argc, char **argv) {
  Board t;
  emptyBoard(t);
  std::cout << "Hello! Welcome to Sudoku Solver" << '\n';
  std::cout << "Please enter values the values (back to back) for each row, no spaces! and 0 for empty cells" << '\n';

  for (int i = 0; i < 9; i++) {
    string tempRow = "";
    std::cout << "Row #" << i + 1 << ": ";
    cin >> tempRow;
    for (int j = 0; j < tempRow.length(); j++) {
      if (tempRow[j] == 0) {
        emptyCell(t,i,(int)tempRow[j] - 48);
      }
      changeValue(t,i,j,(int)tempRow[j] - 48);
    }
  }

  std::cout << '\n';
  std::cout << "Your board should look like this:" << '\n';
  std::cout << '\n';
  sudoku_print(t);
  std::cout << '\n';

  if (hasSolution(t)) {
    std::cout << "The solution to your board is: " << '\n';
    std::cout << '\n';
    solve(t);
    sudoku_print(t);
    std::cout << '\n' << "Bye!" << endl;
  } else {
    std::cout << "I'm sorry but it has no solutions! Try Again!" << '\n';
  }

  return rv;
}
