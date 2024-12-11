#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

bool isBinaryString(const string& s) {
    return all_of(s.begin(), s.end(), [](char c) { return c == '0' || c == '1'; });
}

//Функции, сохраняющие 0
bool isT0(const string& vector) {
    return vector[0] == '0';
}

//Функции, сохраняющие 1
bool isT1(const string& vector) {
    return !vector.empty() && vector.back() == '1';
}

//Самодвойственные функции
bool isS(const string& vector) {
    for (size_t i = 0; i < vector.size() / 2; i++) {
        if (vector[i] == vector[vector.size() - 1 - i]) {
            return false; // Если пара равна, не самодвойственный
        }
    }
    return true; // Если все пары прошли проверку, функция самодвойственная
}

//Монотонные функции
bool isM(const string& vector) {
    // Проверка на монотонность
    for (size_t i = 0; i < vector.size(); ++i) {
        for (size_t j = 0; j < vector.size(); ++j) {
            if ((i & j) == i) {
                if (vector[i] > vector[j]) {
                    return false; // Если f(i) > f(j) при i < j, не монотонная
                }
            }
        }
    }
    return true; // Все проверки пройдены, функция монотонная
}

//Линейные функции
bool isL(const string& vector) {
    size_t length = vector.length();
    int numVariables = log2(length);

    if (numVariables < 1 || length != (1 << numVariables)) {
        return false;
    }

    int c0 = vector[0] - '0';

    if (numVariables == 2) {
        int cy = c0 ^ (vector[1] - '0');
        int cx = c0 ^ (vector[2] - '0');
        int cxy = c0 ^ cx ^ cy ^ (vector[3] - '0');
        return cxy == 0;  // Логическая функция является линейной
    }
    else if (numVariables == 3) {
        bool cz = c0 ^ (vector[1] - '0');
        bool cy = c0 ^ (vector[2] - '0');
        bool cx = c0 ^ (vector[4] - '0');
        bool cxy = c0 ^ cx ^ cy ^ (vector[6] - '0');
        bool cxz = c0 ^ cx ^ cz ^ (vector[5] - '0');
        bool czy = c0 ^ cz ^ cy ^ (vector[3] - '0');
        bool cxyz = c0 ^ cx ^ cy ^ cz ^ (vector[7] - '0');
        return (cxy == 0 && cxz == 0 && czy == 0 && cxyz == 0);
    }
    else if (numVariables == 4) {
        bool cx = c0 ^ (vector[1] - '0');
        bool cy = c0 ^ (vector[2] - '0');
        bool cz = c0 ^ (vector[4] - '0');
        bool cw = c0 ^ (vector[8] - '0');
        bool cxz = c0 ^ cx ^ cz ^ (vector[5] - '0');
        bool cxy = c0 ^ cx ^ cy ^ (vector[6] - '0');
        bool czy = c0 ^ cz ^ cy ^ (vector[3] - '0');
        bool cxyz = c0 ^ cx ^ cy ^ cz ^ (vector[7] - '0');
        bool cwz = c0 ^ cw ^ cz ^ (vector[9] - '0');
        bool cxwz = c0 ^ cw ^ cx ^ cz ^ (vector[10] - '0');
        return (cxy == 0 && cxz == 0 && czy == 0 && cxyz == 0 && cwz == 0 && cxwz == 0);
    }

    return false; // Для других случаев, не определённых выше, возвращаем false
}

//Полнота системы функций
bool isComplete(const unordered_map<string, vector<int>>& vectors) {
    bool hasT0 = false, hasT1 = false, hasS = false, hasM = false, hasL = false;

    // Пройдем по всем векторам и проверим, есть ли хотя бы один '-' в каждом классе
    for (const auto& pair : vectors) {
        const string& vector = pair.first;
        if (!isT0(vector)) hasT0 = true; // Если в классе T0 есть '-', значит условие выполнено
        if (!isT1(vector)) hasT1 = true; // Если в классе T1 есть '-', значит условие выполнено
        if (!isS(vector)) hasS = true;   // Если в классе S есть '-', значит условие выполнено
        if (!isM(vector)) hasM = true;   // Если в классе M есть '-', значит условие выполнено
        if (!isL(vector)) hasL = true;   // Если в классе L есть '-', значит условие выполнено
    }

    // Если в каждом классе есть хотя бы один '-', система считается полной
    return hasT0 && hasT1 && hasS && hasM && hasL;
}

//Таблица классов булевых функций 
void printTable(const unordered_map<string, vector<int>>& vectors) {
    cout << "\nТаблица принадлежности к классам булевых функций:\n";
    cout << setw(10) << "Вектор" << " | "
        << setw(2) << "T0" << " | "
        << setw(2) << "T1" << " | "
        << setw(2) << "S" << " | "
        << setw(2) << "M" << " | "
        << setw(2) << "L" << "\n";
    cout << string(45, '-') << "\n";

    for (const auto& pair : vectors) {
        const string& vector = pair.first;
        cout << setw(10) << vector << " | "
            << setw(2) << (isT0(vector) ? "+" : "-") << " | "
            << setw(2) << (isT1(vector) ? "+" : "-") << " | "
            << setw(2) << (isS(vector) ? "+" : "-") << " | "
            << setw(2) << (isM(vector) ? "+" : "-") << " | "
            << setw(2) << (isL(vector) ? "+" : "-") << "\n";
    }

    // Проверяем полноту после вывода таблицы
    if (isComplete(vectors)) {
        cout << "Система функций является полной.\n";
    }
    else {
        cout << "Система функций не является полной.\n";
    }
}

void menu(unordered_map<string, vector<int>>& vectors) {
    int expressionNumber;
    cout << "Введите количество выражений: ";
    cin >> expressionNumber;
    cin.ignore(); // для очищения буфера ввода после ввода числа

    for (int i = 0; i < expressionNumber; ++i) {
        string vector;
        cout << "Введите вектор: ";
        getline(cin, vector);

        if (isBinaryString(vector) && vectors.find(vector) == vectors.end()) {
            vectors[vector] = {}; // добавляем вектор в словарь
        }
        else {
            cout << "Неверный формат ввода вектора\n";
            return; // выходим из функции на ошибке
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    unordered_map<string, vector<int>> vectors;
    menu(vectors);
    printTable(vectors);

    return 0;
}
