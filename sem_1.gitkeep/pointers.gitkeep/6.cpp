#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int countC = 0;
    int countV = 0;
    string st;
    cout << "Введите строку" << std::endl;
    cin >> st;
    const char* pt = st.c_str();
    for (int i = 0; i < st.length(); i++)
    {
        char tmp = tolower(*pt);
        cout << tmp << std::endl;
        if (tmp == L'а' || tmp == L'е' || tmp == L'и' || tmp == L'о' || tmp == L'у' || tmp == L'э' || tmp == L'ю' || tmp == L'я')
        {
            countV++;
        }
        else { countC++; }
        pt++;
    }

    cout << "Количество гласных:  " << countV << endl;
    cout << "Количество согласных:  " << countC << endl;
    return 0;
}