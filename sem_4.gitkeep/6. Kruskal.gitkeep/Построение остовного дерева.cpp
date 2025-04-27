#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else {
                parent[rootY] = rootX;
                if (rank[rootX] == rank[rootY]) {
                    rank[rootX]++;
                }
            }
        }
    }
};

vector<vector<int>> readMatrixFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        exit(1);
    }

    vector<vector<int>> matrix(10, vector<int>(10));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close();
    return matrix;
}

int main() {
    setlocale(LC_ALL, "RU");
    string filename = "g21.txt"; // Имя файла с матрицей
    vector<vector<int>> matrix = readMatrixFromFile(filename);

    vector<Edge> edges;
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            if (matrix[i][j] != 0) { // Игнорируем нулевые рёбра
                edges.emplace_back(i, j, matrix[i][j]);
            }
        }
    }

    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(10);
    vector<Edge> mst;
    int totalWeight = 0;

    for (const Edge& e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            mst.push_back(e);
            totalWeight += e.weight;
            dsu.unite(e.u, e.v);
            if (mst.size() == 9) break;
        }
    }

    if (mst.size() != 9) {
        cerr << "Граф несвязный. Построение минимального остовного дерева невозможно." << endl;
        return 1;
    }

    // Вывод суммы весов рёбер
    cout << "Сумма весов рёбер минимального остовного дерева: " << totalWeight << endl;

    // Вывод рёбер остовного дерева
    cout << "\nРёбра остовного дерева:" << endl;
    for (const Edge& e : mst) {
        cout << e.u << " - " << e.v << " (вес " << e.weight << ")" << endl;
    }

    // Создание и вывод матрицы смежности остовного дерева
    vector<vector<int>> adjacencyMatrix(10, vector<int>(10, 0));
    for (const Edge& e : mst) {
        adjacencyMatrix[e.u][e.v] = e.weight;
        adjacencyMatrix[e.v][e.u] = e.weight;
    }

    cout << "\nМатрица смежности остовного дерева:" << endl;
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}