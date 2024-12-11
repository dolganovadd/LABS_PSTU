#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string askForVectorInput();
string createVectorManually();
string generateRandomVector();
void displayMenu();
void displayVector(const string& vector);
void displayTruthTable(const string& vector);
string getDNF(const vector<bool>& boolVector);
string getCNF(const vector<bool>& boolVector);
void displayIntermediateResults(const string& vector);
void displayMinimalCovers(const string& vector);
vector<string> quineMcCluskey(const vector<string>& minterms);
vector<vector<string>> groupByOnesCount(const vector<string>& minterms);
bool canCombine(const string& a, const string& b);
string combine(const string& a, const string& b);
void displayImplicantMatrix(const vector<string>& minterms,
    const vector<string>& primeImplicants);
bool covers(const string& primeImplicant, const string& minterm);
vector<string> getMinimalCovers(const vector<string>& minterms,
    const vector<string>& primeImplicants);
bool coversAll(const vector<int>& cover,
    const vector<vector<bool>>& coverageMatrix,
    const vector<string>& minterms);
string getMintermName(const string& minterm);
string getImplicantName(const string& implicant);
std::vector<std::vector<int>> beforePCNF;
std::vector<std::vector<int>> beforePDNF;
void createThuthTable(const string& vector);
void displayFormulas();

int main() {
    setlocale(LC_ALL, "RU");
    string vector = askForVectorInput();
    bool exit = false;

    while (!exit) {
        displayMenu();
        string choice;
        cin >> choice;

        switch (stoi(choice)) {
        case 1:
            displayVector(vector);
            break;
        case 2:
            displayTruthTable(vector);
            break;
        case 3:
            createThuthTable(vector);
            displayFormulas();
            break;
        case 4:
            displayIntermediateResults(vector);
            break;
        case 5:
            displayMinimalCovers(vector);
            break;
        case 6:
            vector = askForVectorInput();
            break;
        case 7:
            exit = true;
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            break;
        }
    }

    return 0;
}

string askForVectorInput() {
    cout << "Хотите создать вектор вручную или случайным образом? (1 - вручную/2 "
        "- случайно)"
        << endl;
    string choice;
    cin >> choice;

    if (choice == "1") {
        return createVectorManually();
    }
    else {
        return generateRandomVector();
    }
}

string createVectorManually() {
    cout << "Введите вектор из 16 символов (0 или 1):" << endl;
    string input;
    cin >> input;

    if (input.length() != 16 || !all_of(input.begin(), input.end(), [](char c) {
        return c == '0' || c == '1';
        })) {
        cout
            << "Неверный ввод. Вектор должен содержать ровно 16 символов (0 или 1)."
            << endl;
        return createVectorManually();
    }

    return input;
}

string generateRandomVector() {
    srand(static_cast<unsigned int>(
        time(0))); 
    string vector(16, '0');

    for (int i = 0; i < 16; i++) {
        vector[i] = rand() % 2 == 0 ? '0' : '1';
    }

    return vector;
}

void displayMenu() {
    cout << "\nМеню:" << endl;
    cout << "1. Вывести созданный вектор" << endl;
    cout << "2. Таблица истинности" << endl;
    cout << "3. СДНФ и СКНФ в виде формул" << endl;
    cout << "4. Промежуточные результаты склеек и импликантная матрица методом "
        "Квайна"
        << endl;
    cout << "5. Все минимальные покрытия (минимизация)" << endl;
    cout << "6. Создать новый вектор" << endl;
    cout << "7. Выход" << endl;
    cout << "Выберите опцию: ";
}

void displayVector(const string& vector) {
    cout << "\nСозданный вектор:" << endl;
    cout << vector << endl;
}

void displayTruthTable(const string& vector) {
    cout << "\nТаблица истинности:" << endl;
    cout << "x1 x2 x3 x4 | F" << endl;
    for (int i = 0; i < 16; i++) {
        string binary = bitset<4>(i).to_string();
        cout << binary[0] << "  " << binary[1] << "  " << binary[2] << "  "
            << binary[3] << "  | " << vector[i] << "   " << endl;
    }
}

void createThuthTable(const string& vector) {
    std::vector<int> tmp;

    for (int i(0), tableIdx(0); i < vector.size(); ++i) {
        for (int j(log2(vector.size()) - 1); j >= 0; --j) {
            tmp.push_back((i >> j) & 1);
        }
        (vector[tableIdx++] == '0') ? beforePCNF.push_back(tmp)
            : beforePDNF.push_back(tmp);
        tmp.clear();
    }
}

void displayFormulas() {
    std::cout << "СКНФ" << std::endl;
    for (int i = 0; i < beforePCNF.size(); ++i) {
        for (int j = 0; j < beforePCNF[i].size(); ++j) {
            if (beforePCNF[i][j] > 0) {
                std::cout << "x" << j + 1;
            }
            else {
                std::cout << "¬x" << j + 1;
            }
            if (j != 3)
                std::cout << "∧";
        }
        if (i != beforePCNF.size() - 1) {
            std::cout << " * ";
        }
    }
    std::cout << '\n';

    std::cout << "СДНФ" << std::endl;
    for (int i = 0; i < beforePDNF.size(); ++i) {
        for (int j = 0; j < beforePDNF[i].size(); ++j) {
            if (beforePDNF[i][j] > 0) {
                std::cout << "x" << j + 1;
            }
            else {
                std::cout << "¬x" << j + 1;
            }
        }
        if (i != beforePDNF.size() - 1) {
            std::cout << " + ";
        }
    }
    std::cout << '\n';

    beforePDNF.clear();
    beforePCNF.clear();
}

void displayIntermediateResults(const string& truthTable) {
    cout << "\nПромежуточные результаты склеек и импликантная матрица методом "
        "Квайна:"
        << endl;
    vector<string> minterms;

    if (truthTable.length() != 16) {
        cerr << "Ошибка: неверная длина таблицы истинности. Ожидалось 16 бит."
            << endl;
        return;
    }

    for (size_t i = 0; i < truthTable.length(); ++i) {
        if (truthTable[i] == '1') {
            minterms.push_back(bitset<4>(i).to_string());
        }
    }

    vector<string> primeImplicants = quineMcCluskey(minterms);

    if (primeImplicants.empty()) {
        cout << "Не найдено первичных импликантов." << endl;
        return;
    }

    cout << "Промежуточные результаты:" << endl;
    for (const auto& implicant : primeImplicants) {
        cout << implicant << endl;
    }

    cout << "\nИмпликантная матрица:" << endl;
    displayImplicantMatrix(minterms, primeImplicants);
}

void displayMinimalCovers(const string& truthTable) {
    cout << "\nВсе минимальные покрытия (минимизация):" << endl;
    vector<string> minterms;

    if (truthTable.length() != 16) {
        cerr << "Ошибка: неверная длина таблицы истинности. Ожидалось 16 бит."
            << endl;
        return;
    }

    for (size_t i = 0; i < truthTable.length(); ++i) {
        if (truthTable[i] == '1') {
            minterms.push_back(bitset<4>(i).to_string());
        }
    }

    vector<string> primeImplicants = quineMcCluskey(minterms);
    vector<string> minimalCovers = getMinimalCovers(minterms, primeImplicants);

    if (minimalCovers.empty()) {
        cout << "Не найдено минимальных покрытий." << endl;
        return;
    }

    string result;
    for (const auto& cover : minimalCovers) {
        if (!result.empty())
            result += " v ";
        result += cover;
    }
    cout << "ДНФmin: " << result << endl;
}

vector<string> quineMcCluskey(const vector<string>& minterms) {
    vector<vector<string>> groups = groupByOnesCount(minterms);
    vector<string> primeImplicants;
    unordered_set<string> uniqueImplicants;

    while (groups.size() > 1) {
        vector<vector<string>> newGroups;
        vector<string> usedMinterms;

        for (size_t i = 0; i < groups.size() - 1; i++) {
            vector<string> combined;
            for (const auto& a : groups[i]) {
                for (const auto& b : groups[i + 1]) {
                    if (canCombine(a, b)) {
                        string combinedTerm = combine(a, b);
                        combined.push_back(combinedTerm);
                        usedMinterms.push_back(a);
                        usedMinterms.push_back(b);
                    }
                }
            }
            if (!combined.empty()) {
                newGroups.push_back(combined);
            }
        }

        for (const auto& group : groups) {
            for (const auto& minterm : group) {
                if (find(usedMinterms.begin(), usedMinterms.end(), minterm) ==
                    usedMinterms.end()) {
                    if (uniqueImplicants.insert(minterm).second) {
                        primeImplicants.push_back(minterm);
                    }
                }
            }
        }

        groups = newGroups;
    }

    if (groups.size() == 1) {
        for (const auto& implicant : groups[0]) {
            if (uniqueImplicants.insert(implicant).second) {
                primeImplicants.push_back(implicant);
            }
        }
    }

    return primeImplicants;
}

vector<vector<string>> groupByOnesCount(const vector<string>& minterms) {
    vector<vector<string>> groups(5);

    for (const auto& minterm : minterms) {
        int onesCount = count(minterm.begin(), minterm.end(), '1');
        groups[onesCount].push_back(minterm);
    }

    groups.erase(
        remove_if(groups.begin(), groups.end(),
            [](const vector<string>& group) { return group.empty(); }),
        groups.end());
    return groups;
}

bool canCombine(const string& a, const string& b) {
    int diffCount = 0;
    for (size_t i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            diffCount++;
        }
    }
    return diffCount == 1;
}

string combine(const string& a, const string& b) {
    string result(a.length(), '-');
    for (size_t i = 0; i < a.length(); i++) {
        if (a[i] == b[i]) {
            result[i] = a[i];
        }
    }
    return result;
}

void displayImplicantMatrix(const vector<string>& minterms,
    const vector<string>& primeImplicants) {
    vector<vector<bool>> coverageMatrix(primeImplicants.size(),
        vector<bool>(minterms.size(), false));

    for (size_t i = 0; i < primeImplicants.size(); i++) {
        for (size_t j = 0; j < minterms.size(); j++) {
            coverageMatrix[i][j] = covers(primeImplicants[i], minterms[j]);
        }
    }

    cout << "       ";
    for (const auto& minterm : minterms) {
        cout << setw(5) << minterm;
    }
    cout << endl;

    for (size_t i = 0; i < primeImplicants.size(); i++) {
        cout << setw(5)
            << primeImplicants[i]; 
        for (size_t j = 0; j < minterms.size(); j++) {
            string cellValue = coverageMatrix[i][j] ? "+" : " ";
            cout << setw(5) << cellValue; 
        }
        cout << endl;
    }
}

bool covers(const string& primeImplicant, const string& minterm) {
    for (size_t i = 0; i < primeImplicant.length(); i++) {
        if (primeImplicant[i] != '-' && primeImplicant[i] != minterm[i]) {
            return false;
        }
    }
    return true;
}

vector<string> getMinimalCovers(const vector<string>& minterms,
    const vector<string>& primeImplicants) {
    vector<vector<bool>> coverageMatrix(primeImplicants.size(),
        vector<bool>(minterms.size(), false));

    for (size_t i = 0; i < primeImplicants.size(); i++) {
        for (size_t j = 0; j < minterms.size(); j++) {
            coverageMatrix[i][j] = covers(primeImplicants[i], minterms[j]);
        }
    }

    vector<vector<int>> covers;
    for (size_t i = 0; i < primeImplicants.size(); i++) {
        covers.push_back({ static_cast<int>(i) });
    }

    for (size_t i = 0; i < covers.size(); i++) {
        for (size_t j = i + 1; j < covers.size(); j++) {
            if (coversAll(covers[i], coverageMatrix, minterms) &&
                coversAll(covers[j], coverageMatrix, minterms)) {
                if (covers[i].size() > covers[j].size()) {
                    covers.erase(covers.begin() + i);
                    i--;
                    break;
                }
                else if (covers[i].size() < covers[j].size()) {
                    covers.erase(covers.begin() + j);
                    j--;
                }
            }
        }
    }

    vector<string> minimalCovers;
    for (const auto& cover : covers) {
        string result;
        for (int index : cover) {
            if (!result.empty())
                result += " + ";
            result += primeImplicants[index];
        }
        minimalCovers.push_back(result);
    }

    return minimalCovers;
}

bool coversAll(const vector<int>& cover,
    const vector<vector<bool>>& coverageMatrix,
    const vector<string>& minterms) {
    vector<bool> covered(minterms.size(), false);
    for (int index : cover) {
        for (size_t j = 0; j < minterms.size(); j++) {
            if (coverageMatrix[index][j]) {
                covered[j] = true;
            }
        }
    }
    return all_of(covered.begin(), covered.end(), [](bool c) { return c; });
}

string getMintermName(const string& minterm) {
    string result;
    for (size_t i = 0; i < minterm.length(); ++i) {
        result += (minterm[i] == '1' ? "x" : "!x") + to_string(i + 1);
    }
    return result;
}

string getImplicantName(const string& implicant) {
    string result;
    for (size_t i = 0; i < implicant.length(); ++i) {
        if (implicant[i] == '1') {
            result += "x" + to_string(i + 1);
        }
        else if (implicant[i] == '0') {
            result += "!x" + to_string(i + 1);
        }
        else {
            result += "-"; 
        }
    }
    return result;
}
