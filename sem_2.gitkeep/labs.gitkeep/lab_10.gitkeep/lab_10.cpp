#include <iostream>
#include <cstdlib>

using namespace std;
void printArray(int** array, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << array[i][j];
		}
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int rows;
	int columns;
	cout << "Введите количество строк";
	cin >> rows;
	cout << "Введите количество столбцов";
	cin >> columns;

	int** array = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		array[i] = new int[columns];
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			array[i][j] = rand() % 100;
		}
	}

	int rowNumber=0;
	int columnNumber=0;

	int** newArray = new int* [rows + 1];

	for (int i = 0; i < rows + 1; ++i) {
		for (int j = 0; j < columns; ++j) {
			newArray[i][j] = array[i][j];
		}
	}

	for (int j = 0; j < columns; ++j) {
		newArray[rowNumber][j] = rand() % 100;
	}

	for (int i = 0; i < rows + 1; ++i) {
		int* tmp = new int[columns + 1];
		for (int j = 0; j < columns; ++j) {
			tmp[j] = newArray[i][j];
		}
		tmp[columnNumber] = rand() % 100;
		delete[] newArray[i];
		newArray[i] = tmp;
	}

	cout << "Исходный массив:";
	printArray(array, rows, columns);

	cout << "Новый массив:";
	printArray(newArray, rows + 1, columns + 1);

	for (int i = 0; i < rows; ++i) {
		delete[] array[i];
	}
	delete[] array;

	for (int i = 0; i < rows + 1; ++i) {
		delete[] newArray[i];
	}
	delete[] newArray;
	return 0;
}