#include "graph.h"
#include <algorithm>
#include <iostream>

using namespace std;


//вычисление факториала числа i
int factorial(int i)
{
    if (i==0) return 1;
    else return i*factorial(i-1);
}
//добавление нового узла
void Graph::addNode(){
    if (size == 0) {
        mat = new int*[++size];

        vertices = new int[size];
        shortWays = new int[size];
        checkNodes = new int[size];
        for (int i(0); i < size; i++) {vertices[i] = 0; shortWays[i] = 0; checkNodes[i] = 1;};

        for (int i(0); i < size; i++){
            mat[i] = new int[size];

            for (int j(0); j<size; j++) {
                mat[i][j] = 0;

            }
        }
    }
    else {


        // Формирование новой матрицы
        int **tmpMat = new int*[++size];

        for (int i(0); i < size; i++){
            tmpMat[i] = new int[size];

            for (int j(0); j<size; j++){
                tmpMat[i][j] = 0;

            }
        }

        // Перезаполнение вспомогательных массивов
        delete [] vertices;
        delete [] shortWays;
        delete [] checkNodes;
        vertices = new int[size];
        shortWays = new int[size];
        checkNodes = new int[size];
        for (int i(0); i < size; i++) {vertices[i] = 0; shortWays[i] = 0; checkNodes[i] = 1;};

        // Перенос значений из меньшей матрицы
        for (int i(0); i<size-1; i++){
            tmpMat[i][i] = mat[i][i];

            for (int j(i+1); j<size-1;j++){
                tmpMat[i][j] = mat[i][j];
                tmpMat[j][i] = mat[j][i];

            }
        }

        // Очищение памяти от старой матрицы
        for (int i(0); i<size-1; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;

        // Перепривязка указателей
        mat = tmpMat;

        tmpMat = 0;

        delete[] tmpMat;
    }
}

//удаление узла
void Graph::delNode(int num){

    int **tmpMat = new int*[--size]; //Создание временной матрицы

    for (int i(0); i < size; i++){ //цикл для заполнения матрицы нулями
        tmpMat[i] = new int[size];

        for (int j(0); j<size; j++){
            tmpMat[i][j] = 0;

        }
    }

   //Удаление и пересоздание массивов vertices, shortWays и checkNodes:
    delete [] vertices;
    delete [] shortWays;
    delete [] checkNodes;
    vertices = new int[size];
    shortWays = new int[size];
    checkNodes = new int[size];
    //цикл по строкам главной матрицы
    for (int i(0); i < size; i++) {vertices[i] = 0; shortWays[i] = 0; checkNodes[i] = 1;};

    for (int i(0); i<size+1; i++){
        if (i < num-1){
            tmpMat[i][i] = mat[i][i];

            for (int j(i+1); j<size+1;j++)
                if (j<num-1){
                    tmpMat[i][j] = mat[i][j];
                    tmpMat[j][i] = mat[j][i];

                }else if (j!=num-1){
                    tmpMat[i][j-1] = mat[i][j];
                    tmpMat[j-1][i] = mat[j][i];

                }

        }
        else if (i!=num-1){
            tmpMat[i-1][i-1] = mat[i][i];
            for (int j(i+1); j<size+1;j++)
                if (j<num-1){
                    tmpMat[i-1][j] = mat[i][j];
                    tmpMat[j][i-1] = mat[j][i];

                }else if (j!=num-1){
                    tmpMat[i-1][j-1] = mat[i][j];
                    tmpMat[j-1][i-1] = mat[j][i];

                }

        }
    }

    for (int i(0); i<size-1; i++){
        delete[] mat[i];

    }
    delete[] mat;

    // Перепривязка указателей
    mat = tmpMat;

    tmpMat = 0;

    delete[] tmpMat; //удалени временной матрицы

}
//Обход в ширину
QString Graph::searchInWidth(int start){
    //Edge e;
    QString dat;
    if (start-1 > size || start-1 < 1) start = 1;
    Q.push(start-1);
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        vertices[node] = 2; // посещенная вершина
        for (int i(0); i < size;i++){
            if (mat[node][i] != 0 && vertices[i] == 0){
                Q.push(i);
                vertices[i] = 1; // обнаруженная вершина
            }
        }
        dat+= QString::number(node+1);
        dat+=' ';

        cout << node + 1 << endl;
    }
    for (int i(0); i < size; i++) vertices[i] = 0;
    return dat;
}

//Обход в глубину
QString Graph::searchInDepth(int start){
    QString dat;
    if (start-1 > size || start-1 < 1) start = 1;
    S.push(start - 1);
    while (!S.empty())
    {
        int node = S.top();
        S.pop();
        if (vertices[node] == 2) continue;
        vertices[node] = 2;
        for (int i(size-1); i >= 0; i--)
            if (mat[node][i] != 0 && vertices[i] != 2){
                S.push(i);
                vertices[i] = 1;
            }
        dat+= QString::number(node+1);
        dat+=' ';
        cout << node + 1 << endl;
    }
    for (int i(0); i < size; i++) vertices[i] = 0;
    return dat;
}

//Алгоритм Дейкстры
void Graph::dijkstra(int start){
    int tmp, minIndx, min;
    int beginIndx = 0;
    if (start-1 < size) beginIndx = start-1;

    for (int i(0); i < size; i++) {vertices[i] = 0; shortWays[i] = INF; checkNodes[i] = 1;};

    shortWays[beginIndx] = 0;
    do {
        minIndx = INF;
        min = INF;
        for (int i(0); i<size;i++){
            if (checkNodes[i] == 1 && shortWays[i] < min){
                min = shortWays[i];
                minIndx = i;
            }
        }
        if (minIndx != INF){
            for (int i(0); i < size; i++){
                if (mat[minIndx][i] > 0){
                    tmp = min + mat[minIndx][i];
                    if (tmp < shortWays[i]) shortWays[i] = tmp;
                }
            }
            checkNodes[minIndx] = 0;
        }
    } while (minIndx < INF);
    delete way;
    way = new int[size]{};
    int end = size-2;
    way[0] = end+1;
    int k = 1;
    int weight = shortWays[end];

    while (end !=beginIndx) {
        for (int i(0); i < size; i++)
            if (mat[i][end] != 0){
                int tmp = weight - mat[i][end];
                if (tmp == shortWays[i]){
                    weight = tmp;
                    end = i;
                    way[k++] = i + 1;
                }
            }
    }
    lastIndx = k;
}

//отображение графа
QString Graph::showw(){
    QString data;
    cout << endl;
    for (int i(lastIndx-1); i >= 0; i--) {
        cout << way[i] << ' ';
        data+= QString::number(way[i]);
        data+= ' ';
    }
    cout << endl;
    return data;
}
//вес узла
void Graph::setMat(int firstVert, int secondVert, int weight){
    if (firstVert-1 < size && secondVert-1 < size){ //проверка, что индексы вершин находятся в пределах матрицы
        mat[firstVert-1][secondVert-1] = weight;
    }
}





