#include <iostream>

using namespace std;

int main() {

    int str_arr, col_arr, cnt;
    cin >> str_arr >> col_arr >> cnt;
    int array[str_arr][col_arr];

    int num[cnt];
    for (int i = 0; i < cnt; i++) {
        num[i] = i + 1;
    }

    for (int i = 0; i < str_arr; i++) {
        for (int j = 0; j < col_arr; j++) {
            array[i][j] = 0;
        }
    }

    for (int i = 0, k = 0; i < str_arr; k++, i++) {
        for (int n = 0; n < col_arr - k; n++) {
            array[i + n][n] = num[k % cnt];
        }
    }
    for (int i = 0; i < str_arr; cout << endl, i++)
        for (int j = 0; j < col_arr; cout << array[i][j] << " ", j++);

    return 0;
}