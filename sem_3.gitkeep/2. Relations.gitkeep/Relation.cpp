#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Relation {
public:
    Relation(const string& filename) {
        readFromFile(filename);
    }

    void checkProperties() {
        cout << "Свойства отношения:\n";
        cout << "Рефлексивность: " << (isReflexive() ? "Да" : "Нет") << endl;
        cout << "Антирефлексивность: " << (isIrreflexive() ? "Да" : "Нет") << endl;
        cout << "Симметричность: " << (isSymmetric() ? "Да" : "Нет") << endl;
        cout << "Антисимметричность: " << (isAntisymmetric() ? "Да" : "Нет") << endl;
        cout << "Ассиметричность: " << (isAsymmetric() ? "Да" : "Нет") << endl;
        cout << "Транзитивность: " << (isTransitive() ? "Да" : "Нет") << endl;
        cout << "Связность: " << (isConnected() ? "Да" : "Нет") << endl;
    }

private:
    vector<vector<int>> matrix;

    void readFromFile(const string& filename) { //Метод для чтения матрицы из файла
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка подключения к файлу!" << endl;
            exit(1);
        }

        vector<int> row;
        while (!file.eof()) {
            int value;
            if (file >> value) {
                row.push_back(value);
            }
            if (file.peek() == '\n' || file.eof()) {
                if (!row.empty()) {
                    matrix.push_back(row);
                    row.clear();
                }
            }
        }

        file.close();
    }

    // Проверка рефлексивности
    bool isReflexive() {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            if (matrix[i][i] == 0) {
                return false;
            }
        }
        return true;
    }

    // Проверка антирефлексивности
    bool isIrreflexive() {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            if (matrix[i][i] == 1) {
                return false;
            }
        }
        return true;
    }

    // Проверка симметричности
    bool isSymmetric() {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    // Проверка антисимметричности
    bool isAntisymmetric() {
        int n = matrix.size();
        bool hasOneOnDiagonal = false; // Флаг для проверки наличия единицы на главной диагонали

        for (int i = 0; i < n; ++i) {
            if (matrix[i][i] == 1) {
                hasOneOnDiagonal = true; // Если нашли единицу на диагонали
            }
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1 && matrix[j][i] == 1 && i != j) {
                    return false; // Если обе связи существуют для разных элементов
                }
            }
        }

        return hasOneOnDiagonal; // Возвращаем true только если было найдено хотя бы одно соединение на диагонали
    }


    // Проверка ассиметричности
    bool isAsymmetric() {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1 && matrix[j][i] == 1) {
                    return false; // Если существует обратная связь
                }
            }
        }
        return true;
    }

    // Проверка транзитивности
    bool isTransitive() {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[i][k] == 0) {
                        return false; // Транзитивность нарушена
                    }
                }
            }
        }
        return true;
    }

    // Проверка связности
    bool isConnected() {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            bool connected = false;
            for (int j = 0; j < n; ++j) {
                if (i != j && matrix[i][j] == 1) {
                    connected = true;
                    break;
                }
            }
            if (!connected) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Relation relation("m1.txt");
    relation.checkProperties();
    return 0;
}
