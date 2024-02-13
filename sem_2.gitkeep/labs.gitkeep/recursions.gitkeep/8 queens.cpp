
#include <iostream>
using namespace std;

int board[8][8];
const int queen = -1;
void resetBoard();
void showBoard();
bool checkQueen(int i);
void setQueen(int i, int j);
void deleteQueen(int i, int j);

void resetBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = 0;
		}
	}
}

void showBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == queen) {
				cout<< "[Q] ";
			}
			else {
				cout<< "[ ] ";
			}
		}
		cout << endl;
	}
}

void setQueen(int x, int j) {
	int d; //диагональ
	for (int i = 0; i < 8; ++i) { //сначала увеличим, потом делаем тело
		board[i][j]++; //указываем на клетку, атакуемую по вертикали
		board[x][i]++; //указываем на клетку по горизонтали

		d = j - x + i; //вычисляем 1 диагональ
		if (d >= 0 && d < 8) { //проверяем, что ферзь не за пределами доски
			board[i][d]++;
		}
		d = j + x - i;//вычисляем 2 диагональ

		if (d >= 0 && d < 8) { //проверяем, что ферзь не за пределами доски
			board[i][d]++;
		}
	}
	board[x][j] = queen;
}

void deleteQueen(int x, int j) {
	int d; //диагональ
	for (int i = 0; i < 8; ++i) { //сначала увеличим, потом делаем тело
		board[i][j]--; //указываем на клетку, атакуемую по вертикали
		board[x][i]--; //указываем на клетку по горизонтали

		d = j - x + i; //вычисляем 1 диагональ
		if (d >= 0 && d < 8) { //проверяем, что ферзь не за пределами доски
			board[i][d]--;
		}
		d = j + x - i;//вычисляем 2 диагональ

		if (d >= 0 && d < 8) { //проверяем, что ферзь не за пределами доски
			board[i][d]--;
		}
	}
	board[x][j] = 0;
}

//на вход достаточно подать номер строки 
bool checkQueen(int i) {
	bool result = false;

	for (int j = 0; j < 8; ++j) {
		if (board[i][j] == 0) {
			setQueen(i, j); //пробуем поставить ферзя и разметить клетки под боем  

			if (i == 7) { result = true; }
			else if (!(result = checkQueen(i + 1))) { deleteQueen(i, j); }
		
		}
		if (result) break;
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	resetBoard();
	checkQueen(n);
	showBoard();
	return 0;
}