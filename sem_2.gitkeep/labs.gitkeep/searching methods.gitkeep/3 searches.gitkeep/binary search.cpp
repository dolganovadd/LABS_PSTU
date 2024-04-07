#include <iostream>
using namespace std;

int BINsearch(int arr[], int left, int right, int find) {
    bool flag = false;
    //int left = 0; //����� ������� ���������
    //int right = Size-1; //������ ������� ���������
    int mid;
    while ((left <= right) && (flag != true)) {
        mid = (left + right) / 2; //���������� ������� �������� mid
        if (arr[mid] == find) { //������������ �������� ���� � ��������� mid
            flag = true;
            return mid;
        }
        //���� ������� �������� �������� ��������� ������ �������� ��������� � �������� mid,
        //�� �������� �������� ����� ����� � ����� �������� ���������
        if (arr[mid] > find) {
            right = mid - 1;
        }
        //����� ����� ����� ������� � ������ �������� ���������
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    system("chcp 1251");
    int arr[] = { 2, 3, 4, 5, 6, 7, 8 };
    int Size = 7;
    int find = 6;

    int result = BINsearch(arr, 0, Size, find);

    if (result == -1) {
        cout << "������� �� ������" << endl;
    }
    else {
        cout << "������� ������ � ������� " << result << endl;
    }

    return 0;
}

