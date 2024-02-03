#include <iostream>
using namespace std;
int neg_str(int arr[3][3], int num, int size) {
	bool flag = 1; //проверяем, имеет строка отрицательные элементы или нет 

	for (int i = 0; i < 3; i++) {
		if (arr[num][i] < 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}
int main() {
	int size;

	cin >> size;
	int arr[3][3] = { {-1,2,0},{1,-1,1},{3,2, 1} };

	for (int i = 0; i < size; cout << endl, i++)
		for (int j = 0; j < size; cout << arr[i][j] << " ", j++);
	cout << endl;

	for (int i = 0; i < size; i++) {
		if (neg_str(arr, i, size) == 0) {
			for (int k = i; k < size - 1; k++) {
				for (int j = 0; j < size; j++) {
					arr[k][j] = arr[k + 1][j]; //значение текущего элемента заменяем на значение следующего элемента в следующей строке
				}
			}
			for (int j = 0; j < size; j++) {
				arr[size - 1][j] = 0; //обнуляет последнюю строку 
			}
			i--;
			for (int i = 0; i < size; cout << endl, i++)
				for (int j = 0; j < size; cout << arr[i][j] << " ", j++);
			cout << endl;
		}
		
	}

	return 0;
}

/* Результаты 
1. int arr[3][3] = { {-1,2,0},{1,-1,1},{3,2, 1} };

-1 2 0
1 -1 1
3 2 1

1 -1 1
3 2 1
0 0 0

3 2 1
0 0 0
0 0 0

2. int arr[3][3] = { {1,-4,2},{-5,2,1},{-1,2, 1} };

1 -4 2
-5 2 1
-1 2 1

-5 2 1
-1 2 1
0 0 0

-1 2 1
0 0 0
0 0 0

0 0 0
0 0 0
0 0 0

3.int arr[3][3] = { {1,3,2},{2,2,1},{5,-3, 1} };

1 3 2
2 2 1
5 -3 1

1 3 2
2 2 1
0 0 0

*/