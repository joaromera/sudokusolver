#include <iostream>

using namespace std;

// Function descriptions in sudoku.h

typedef int Board[9][9];

void sudoku_print(Board t) {
	for (int i = 0; i < 9; i++) {
		cout << " ";
		if (i % 3 == 0) {
			cout << "";
		}
		for (int j = 0; j < 9; j++) {
			if (j == 3 || j == 6) {
				cout << "| ";
			}
			if (t[i][j] == 0) {
				cout << "_";
			} else {
				cout << t[i][j];
			}
			cout << " ";
		}
		cout << endl;
		if (i == 8) {
		} else if (i == 2 || i == 5) {
			cout << "----------------------";
		}
		if (i == 2 || i == 5) {
			cout << endl;
		}
	}
}

bool isEmptyCell(Board t, int f, int c) {
	return t[f][c] == 0;
}

void emptyBoard(Board t) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			t[i][j] = 0;
		}
	}
}

int nmbrEmptyCells(Board t) {
	int total = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (t[i][j] == 0) {
				total++;
			}
		}
	}
	return total;
}

int firstEmptyCellRow(Board t) {
	int row = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (t[i][j] == 0 && row == -1) {
				row = i;
			}
		}
	}
	return row;
}

int firstEmptyCellColumn(Board t) {
	int column = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (t[i][j] == 0 && column == -1) {
				column = j;
			}
		}
	}
	return column;
}

int cellValue(Board t, int f, int c) {
	return t[f][c];
}

void changeValue(Board t, int f, int c, int v) {
	t[f][c] = v;
}

void emptyCell(Board t, int f, int c) {
	t[f][c] = 0;
}

bool isValidBoard(Board t) {
	bool valido = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (t[i][j] > 9 || t[i][j] < 0) {
				valido = false;
			}
		}
	}
	return valido;
}

int repetitions(int l[]){
	int result = 0;
	for (int i = 0; i < 9; i++){
		if (l[i] != 0){
			for (int j = 0; j < 9; j++){
				if (i != j && l[i] == l[j]){
					result++;
				}
			}
		}
	}
	return result;
}

bool partiallySolvedRow(Board t){
	int result = 0;
	for (int i = 0; i < 9; i++){
		result += repetitions(t[i]);
	}
	return (result == 0);
}

bool partiallySolvedColumn(Board t){
	int result = 0;
	for (int j = 0; j < 9; j++){
		int subArray[9];
		for (int i = 0; i < 9; i++){
			subArray[i] = t[i][j];
		}
		result += repetitions(subArray);
	}
	return (result == 0);
}

bool partiallySolvedRegion(Board t) {
	int result = 0;
	for(int i = 0; i < 9; i = i + 3) {
		for(int j = 0; j < 9; j = j + 3) {
			int subArray[9];
			int pos = 0;
			for(int k = i; k < i + 3; k++) {
				for(int l = j; l < j + 3; l++) {
					subArray[pos] = t[k][l];
					pos++;
				}
			}
			result += repetitions(subArray);
		}
	}
	return (result == 0);
}

bool isPartiallySolved(Board t) {
	return (isValidBoard(t) &&
			partiallySolvedRow(t) &&
			partiallySolvedColumn(t) &&
			partiallySolvedRegion(t));
}

bool isTotallySolved(Board t) {
	return (isPartiallySolved(t) && nmbrEmptyCells(t) == 0);
}

bool subBoard(Board t0, Board t1) {
	int differentCells = 0;
	for(int i = 0; i < 9 && differentCells == 0; i++){
		for(int j = 0; j < 9 && differentCells == 0; j++){
			if(t0[i][j] != 0 && (t0[i][j] != t1[i][j])){
				differentCells++;
			}
		}
	}
	return differentCells == 0;
}

void copyBoard(Board t, Board s){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			s[i][j] = t[i][j];
		}
	}
}

bool solving(Board t){

	if (isTotallySolved(t))
		return true;
	if (isPartiallySolved(t) == false)
		return false;

	for (int f = 0; f < 9; f++) {
		for (int c = 0; c < 9; c++) {
			if (t[f][c] == 0) {
				for (int v = 1; v < 10; v++) {
					changeValue(t, f, c, v);

					if (solving(t) == true) {
						return true;
					} else {
						emptyCell(t, f, c);
					}
				}
				if (t[f][c] == 0) {
					return false;
				}
			}
		}
	}
}

bool solve(Board t){
	Board boardTemp;
	copyBoard(t,boardTemp);
	if (solving(t) == false)
		copyBoard(boardTemp, t);
	return (isTotallySolved(t));
}

bool hasSolution(Board t){
	Board boardTemp;
	copyBoard(t,boardTemp);
	return solve(boardTemp);
}
