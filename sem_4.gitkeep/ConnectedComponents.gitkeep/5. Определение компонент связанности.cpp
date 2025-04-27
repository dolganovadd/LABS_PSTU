#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int SIZE = 10; // размер матрицы 10x10

// Функция для преобразования ориентированного графа в неориентированный
void makeUndirected(const vector<vector<int>>& adjMatrix, vector<vector<int>>& undirectedMatrix) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (adjMatrix[i][j] == 1 || adjMatrix[j][i] == 1) {
                undirectedMatrix[i][j] = 1;
                undirectedMatrix[j][i] = 1;
            }
        }
    }
}

// Поиск компонент связанности с помощью BFS
void bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    component.push_back(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < SIZE; ++i) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
                component.push_back(i);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    ifstream inFile("g14.txt");
    if (!inFile) {
        cerr << "Не удалось открыть файл." << endl;
        return 1;
    }

    vector<vector<int>> adjMatrix(SIZE, vector<int>(SIZE, 0));
    // Чтение матрицы смежности из файла
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            inFile >> adjMatrix[i][j];
        }
    }
    inFile.close();

    // Преобразуем ориентированный граф в неориентированный
    vector<vector<int>> undirectedMatrix(SIZE, vector<int>(SIZE, 0));
    makeUndirected(adjMatrix, undirectedMatrix);

    // Матрица достижимости
    vector<vector<int>> reachabilityMatrix(SIZE, vector<int>(SIZE, 0));

    // Поиск компонент связанности
    vector<bool> visited(SIZE, false);
    vector<vector<int>> components;

    for (int i = 0; i < SIZE; ++i) {
        if (!visited[i]) {
            vector<int> component;
            bfs(i, undirectedMatrix, visited, component);
            components.push_back(component);

            // Обновление матрицы достижимости
            for (int node : component) {
                for (int other : component) {
                    reachabilityMatrix[node][other] = 1;
                }
            }
        }
    }

    // Вывод матрицы достижимости
    cout << "Матрица достижимости:" << endl;
    for (const auto& row : reachabilityMatrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    // Вывод количества компонент связанности и их вершин
    cout << "Количество компонент связанности: " << components.size() << endl;
    for (size_t i = 0; i < components.size(); ++i) {
        cout << "Компонента " << i + 1 << ": ";
        for (int vertex : components[i]) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
