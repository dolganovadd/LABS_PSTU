#include <iostream>   
#include <vector>     
#include <sstream>    
#include <cstdlib>    
#include <ctime>      

using namespace std;   

// Задаем границы универсума
const int UNIVERSE_MIN = -50; // Минимальное значение универсума
const int UNIVERSE_MAX = 50;   // Максимальное значение универсума
const int UNIVERSE_SIZE = UNIVERSE_MAX - UNIVERSE_MIN + 1; // Размер универсума

// Объявляем класс SetCalculator для работы с множествами
class SetCalculator {
public:
    using IntSet = vector<bool>; 

    // Конструктор класса
    SetCalculator() {
        sets.reserve(10); // Резервируем место для множеств (до 10)
        minAllowedValue = UNIVERSE_MIN; // Устанавливаем минимальное допустимое значение
        maxAllowedValue = UNIVERSE_MAX; // Устанавливаем максимальное допустимое значение
        allowNegative = true; // Разрешаем отрицательные числа
        allowEven = true; // Разрешаем четные числа
        allowOdd = true; // Разрешаем нечетные числа
    }

    // Методы класса
    void addRandomSet(); // Добавление случайного множества
    void addManualSet(); // Добавление множества вручную
    size_t displaySets(); // Отображение всех множеств
    void unionSets(int a, int b);  // Объединение множеств
    void differenceSets(int a, int b); // Разность множеств
    void intersectionSets(int a, int b); // Пересечение множеств
    void symmetricDifference(int a, int b); // Симметрическая разность
    void complementSet(int index); // Дополнение множества
    void calculateExpression(const string& expression); // Расчет выражения
    void setConditions(); // Установка условий

private:
    vector<IntSet> sets; 

    // Переменные для условий
    int minAllowedValue; // Минимально допустимое значение
    int maxAllowedValue; // Максимально допустимое значение
    bool allowNegative;   // Флаг для разрешения отрицательных чисел
    bool allowEven;       // Флаг для разрешения четных чисел
    bool allowOdd;        // Флаг для разрешения нечетных чисел

    void addToSet(IntSet& set, int value); 
    IntSet parseExpression(const string& expression); 
    bool checkConditions(int value); 
};

// Метод добавления элемента в множество
void SetCalculator::addToSet(IntSet& set, int value) {
    if (checkConditions(value)) { // Проверяем условия
        set[value - UNIVERSE_MIN] = true; // Добавляем значение в множество
    }
    else {
        cout << "Значение " << value << " не соответствует условиям." << endl; 
    }
}

// Метод проверки, соответствует ли значение условиям
bool SetCalculator::checkConditions(int value) {
    if (value < minAllowedValue || value > maxAllowedValue) return false; // Проверка по границам
    if (!allowNegative && value < 0) return false; // Проверка на отрицательные значения
    if (!allowEven && value % 2 == 0) return false; // Проверка на четные значения
    if (!allowOdd && value % 2 != 0) return false; // Проверка на нечетные значения
    return true; 
}

// Метод добавления случайного множества
void SetCalculator::addRandomSet() {
    IntSet newSet(UNIVERSE_SIZE, false); // Создаем новое множество заполненное ложными значениями
    int size = rand() % (UNIVERSE_SIZE + 1); // Генерируем случайный размер множества
    while (size-- > 0) {
        int value = rand() % UNIVERSE_SIZE + UNIVERSE_MIN; // Генерируем случайное значение из универсума
        addToSet(newSet, value); // Добавляем значение в множество
    }
    sets.push_back(newSet); // Сохраняем множество
}

// Метод для ручного добавления множества
void SetCalculator::addManualSet() {
    IntSet newSet(UNIVERSE_SIZE, false); // Создаем новое множество
    string input; 
    cout << "Введите числа для множества (q для окончания ввода):" << endl;
    while (true) { 
        cin >> input; 
        if (input == "q") break; 
        try {
            int number = stoi(input); // Пробуем преобразовать ввод в число
            addToSet(newSet, number); // Добавляем число в множество
        }
        catch (invalid_argument&) { 
            cout << "Некорректный ввод, попробуйте снова." << endl;
        }
    }
    sets.push_back(newSet); // Сохраняем множество
}

// Метод отображения всех множеств
size_t SetCalculator::displaySets() {
    for (size_t i = 0; i < sets.size(); ++i) { // Проходим по всем множествам
        cout << "Множество " << (i + 1) << ": { ";
        for (int j = 0; j < UNIVERSE_SIZE; ++j) {
            if (sets[i][j]) { // Если элемент существует в множестве
                cout << (j + UNIVERSE_MIN) << " "; // Выводим элемент
            }
        }
        cout << "}" << endl; 
    }
    return sets.size(); // Возвращаем количество множеств
}

// Метод объединения двух множеств
void SetCalculator::unionSets(int a, int b) {
    IntSet resultSet(UNIVERSE_SIZE, false); // Создаем результирующее множество
    for (int i = 0; i < UNIVERSE_SIZE; ++i) {
        resultSet[i] = sets[a][i] || sets[b][i]; // Объединяем множества
    }
    cout << "Объединение множеств: { ";
    for (int j = 0; j < UNIVERSE_SIZE; ++j) {
        if (resultSet[j]) { // Если элемент существует в результирующем множестве
            cout << (j + UNIVERSE_MIN) << " "; // Выводим элемент
        }
    }
    cout << "}" << endl;
}

// Метод вычисления разности двух множеств
void SetCalculator::differenceSets(int a, int b) {
    IntSet resultSet(UNIVERSE_SIZE, false); // Создаем результирующее множество
    for (int i = 0; i < UNIVERSE_SIZE; ++i) {
        resultSet[i] = sets[a][i] && !sets[b][i]; // Вычисляем разность
    }
    cout << "Разность множеств: { ";
    for (int j = 0; j < UNIVERSE_SIZE; ++j) {
        if (resultSet[j]) {
            cout << (j + UNIVERSE_MIN) << " "; // Выводим элемент
        }
    }
    cout << "}" << endl; 
}

// Метод вычисления пересечения двух множеств
void SetCalculator::intersectionSets(int a, int b) {
    IntSet resultSet(UNIVERSE_SIZE, false); // Создаем результирующее множество
    for (int i = 0; i < UNIVERSE_SIZE; ++i) {
        resultSet[i] = sets[a][i] && sets[b][i]; // Вычисляем пересечение
    }
    cout << "Пересечение множеств: { ";
    for (int j = 0; j < UNIVERSE_SIZE; ++j) {
        if (resultSet[j]) {
            cout << (j + UNIVERSE_MIN) << " "; // Выводим элемент
        }
    }
    cout << "}" << endl; 
}

// Метод вычисления симметрической разности двух множеств
void SetCalculator::symmetricDifference(int a, int b) {
    IntSet resultSet(UNIVERSE_SIZE, false); // Создаем результирующее множество
    for (int i = 0; i < UNIVERSE_SIZE; ++i) {
        resultSet[i] = sets[a][i] != sets[b][i]; // Вычисляем симметрическую разность
    }
    cout << "Симметрическая разность: { ";
    for (int j = 0; j < UNIVERSE_SIZE; ++j) {
        if (resultSet[j]) {
            cout << (j + UNIVERSE_MIN) << " "; // Выводим элемент
        }
    }
    cout << "}" << endl; 
}

// Метод вычисления дополнения множества
void SetCalculator::complementSet(int index) {
    IntSet resultSet(UNIVERSE_SIZE, false); // Создаем результирующее множество
    for (int i = 0; i < UNIVERSE_SIZE; ++i) {
        resultSet[i] = !sets[index][i]; // Вычисляем дополнение
    }
    cout << "Дополнение до универсума: { ";
    for (int j = 0; j < UNIVERSE_SIZE; ++j) {
        if (resultSet[j]) {
            cout << (j + UNIVERSE_MIN) << " "; // Выводим элемент
        }
    }
    cout << "}" << endl; 
}

// Метод парсинга выражения
SetCalculator::IntSet SetCalculator::parseExpression(const string& expression) {
    IntSet resultSet(UNIVERSE_SIZE, false); // Создаем результирующее множество
    stringstream ss(expression); // Создаем поток для обработки строки
    string token; // Переменная для хранения токенов

    while (ss >> token) { // Считываем токены из строки
        if (token == "1" || token == "2" || token == "3") { // Если токен - индекс множества
            int setIndex = stoi(token) - 1; // Преобразуем токен в индекс
            if (setIndex >= 0 && setIndex < sets.size()) { // Проверяем действительность индекса
                for (int i = 0; i < UNIVERSE_SIZE; ++i) {
                    resultSet[i] = resultSet[i] || sets[setIndex][i]; // Объединяем множество
                }
            }
        }
        else if (token == "U" || token == "u") { // Если токен - объединение
            ss >> token; // Считываем следующий токен
            if (token == "1" || token == "2" || token == "3") {
                int setIndex = stoi(token) - 1; // Преобразуем токен в индекс
                if (setIndex >= 0 && setIndex < sets.size()) {
                    for (int i = 0; i < UNIVERSE_SIZE; ++i) {
                        resultSet[i] = resultSet[i] || sets[setIndex][i]; // Объединяем множество
                    }
                }
            }
        }
        else if (token == "\\") { // Если токен - разность
            IntSet tempSet = resultSet; // Сохраняем текущее множество
            ss >> token; // Считываем следующий токен
            if (token == "1" || token == "2" || token == "3") {
                int setIndex = stoi(token) - 1; // Преобразуем токен в индекс
                if (setIndex >= 0 && setIndex < sets.size()) {
                    for (int i = 0; i < UNIVERSE_SIZE; ++i) {
                        resultSet[i] = tempSet[i] && !sets[setIndex][i]; // Вычисляем разность
                    }
                }
            }
        }
        else if (token == "S") { // Если токен - симметрическая разность
            IntSet tempSet = resultSet; // Сохраняем текущее множество
            ss >> token; // Считываем следующий токен
            if (token == "1" || token == "2" || token == "3") {
                int setIndex = stoi(token) - 1; // Преобразуем токен в индекс
                if (setIndex >= 0 && setIndex < sets.size()) {
                    for (int i = 0; i < UNIVERSE_SIZE; ++i) {
                        resultSet[i] = (tempSet[i] && !sets[setIndex][i]) || (!tempSet[i] && sets[setIndex][i]); // Симметрическая разность
                    }
                }
            }
        }
        else if (token == "C" || token == "c") { // Если токен - дополнение
            ss >> token; // Считываем следующий токен
            if (token == "1" || token == "2" || token == "3") {
                int setIndex = stoi(token) - 1; // Преобразуем токен в индекс
                if (setIndex >= 0 && setIndex < sets.size()) {
                    IntSet complementSet(UNIVERSE_SIZE, false); // Создаем множество дополнения
                    for (int i = 0; i < UNIVERSE_SIZE; ++i) {
                        complementSet[i] = !sets[setIndex][i]; // Вычисляем дополнение
                    }
                    for (int i = 0; i < UNIVERSE_SIZE; ++i) {
                        resultSet[i] = resultSet[i] || complementSet[i]; // Объединяем с дополнением
                    }
                }
            }
        }
        else if (token == "n") { // Если токен - пересечение
            IntSet tempSet = resultSet; // Сохраняем текущее множество
            ss >> token; // Считываем следующий токен
            if (token == "1" || token == "2" || token == "3") {
                int setIndex = stoi(token) - 1; // Преобразуем токен в индекс
                if (setIndex >= 0 && setIndex < sets.size()) {
                    for (int i = 0; i < UNIVERSE_SIZE; ++i) {
                        resultSet[i] = tempSet[i] && sets[setIndex][i]; // Вычисляем пересечение
                    }
                }
            }
        }
    }
    return resultSet; // Возвращаем результирующее множество
}

// Метод вычисления выражения и вывод результата
void SetCalculator::calculateExpression(const string& expression) {
    IntSet result = parseExpression(expression); // Парсим выражение
    cout << "Результат: { ";
    for (int j = 0; j < UNIVERSE_SIZE; ++j) {
        if (result[j]) { // Если элемент существует в результирующем множестве
            cout << (j + UNIVERSE_MIN) << " "; // Выводим элемент
        }
    }
    cout << "}" << endl; // Закрываем множество
}

// Метод установки условий для ввода элементов
void SetCalculator::setConditions() {
    cout << "Установите условия для ввода элементов:\n"; // Выводим сообщение
    cout << "1. Разрешить отрицательные числа? (1 - Да, 0 - Нет): ";
    cin >> allowNegative; 
    cout << "2. Разрешить четные числа? (1 - Да, 0 - Нет): ";
    cin >> allowEven; 
    cout << "3. Разрешить нечетные числа? (1 - Да, 0 - Нет): ";
    cin >> allowOdd; 
    cout << "4. Укажите минимальное значение: ";
    cin >> minAllowedValue; 
    cout << "5. Укажите максимальное значение: ";
    cin >> maxAllowedValue; 
}

int main() {
    setlocale(LC_ALL, "RU"); 
    srand(static_cast<unsigned>(time(0))); 
    SetCalculator calc; 
    int choice; 

    while (true) { // Основной цикл программы
        cout << "\nМеню:\n" // Вывод меню
            << "1. Установить условия ввода\n"
            << "2. Добавить случайное множество\n"
            << "3. Добавить вручную множество\n"
            << "4. Отобразить множества\n"
            << "5. Объединение\n"
            << "6. Разность\n"
            << "7. Симметрическая разность\n"
            << "8. Пересечение\n"
            << "9. Дополнение\n"
            << "10. Расчет выражения\n"
            << "11. Выход\n"
            << "Ваш выбор: ";
        cin >> choice; // Читаем выбор пользователя

        switch (choice) { // Обрабатываем выбор
        case 1:
            calc.setConditions(); // Устанавливаем условия
            break;
        case 2:
            calc.addRandomSet(); // Добавляем случайное множество
            break;
        case 3:
            calc.addManualSet(); // Добавляем вручную множество
            break;
        case 4:
            calc.displaySets(); // Отображаем все множества
            break;
        case 5: {
            int a, b;
            cout << "Введите индексы множеств для объединения (1-" << calc.displaySets() << "): ";
            cin >> a >> b; 
            if (a > 0 && b > 0 && a <= calc.displaySets() && b <= calc.displaySets()) {
                calc.unionSets(a - 1, b - 1); // Выполняем объединение
            }
            else {
                cout << "Некорректные индексы." << endl; 
            }
            break;
        }
        case 6: {
            int a, b;
            cout << "Введите индексы множеств для разности (1-" << calc.displaySets() << "): ";
            cin >> a >> b;
            if (a > 0 && b > 0 && a <= calc.displaySets() && b <= calc.displaySets()) {
                calc.differenceSets(a - 1, b - 1); // Выполняем разность
            }
            else {
                cout << "Некорректные индексы." << endl; 
            }
            break;
        }
        case 7: {
            int a, b;
            cout << "Введите индексы множеств для симметрической разности (1-" << calc.displaySets() << "): ";
            cin >> a >> b; 
            if (a > 0 && b > 0 && a <= calc.displaySets() && b <= calc.displaySets()) {
                calc.symmetricDifference(a - 1, b - 1); // Выполняем симметрическую разность
            }
            else {
                cout << "Некорректные индексы." << endl; 
            }
            break;
        }
        case 8: {
            int a, b;
            cout << "Введите индексы множеств для пересечения (1-" << calc.displaySets() << "): ";
            cin >> a >> b; 
            if (a > 0 && b > 0 && a <= calc.displaySets() && b <= calc.displaySets()) {
                calc.intersectionSets(a - 1, b - 1); // Выполняем пересечение
            }
            else {
                cout << "Некорректные индексы." << endl; 
            }
            break;
        }
        case 9: {
            int index;
            cout << "Введите индекс множества для дополнения (1-" << calc.displaySets() << "): ";
            cin >> index; 
            if (index > 0 && index <= calc.displaySets()) {
                calc.complementSet(index - 1); // Выполняем дополнение
            }
            else {
                cout << "Некорректный индекс." << endl; 
            }
            break;
        }
        case 10: {
            string expression;
            cout << "Введите выражение (\\ - разность, S - симметрическая разность, U - объединение, n - пересечение, C - дополнение (пр. С 1)): ";
            cin.ignore(); // Игнорируем предыдущий ввод
            getline(cin, expression); // Считываем всю строку как выражение
            calc.calculateExpression(expression); // Вычисляем выражение
            break;
        }
        case 11:
            return 0; 
        default:
            cout << "Некорректный выбор" << endl; 
        }
    }
}
