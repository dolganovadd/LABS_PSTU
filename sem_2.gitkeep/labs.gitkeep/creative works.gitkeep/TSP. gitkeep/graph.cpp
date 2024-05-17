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

//отображение графа
void Graph::show(){
    //циклы для перебора строк и столбцов матрицы
    for (int i(0); i<size; cout<<endl, i++) {
        for (int j(0); j<size; j++) {
            cout << mat[i][j] << ' ';
        }
    }
}
//вес узла
void Graph::setMat(int firstVert, int secondVert, int weight){
    if (firstVert-1 < size && secondVert-1 < size){ //проверка, что индексы вершин находятся в пределах матрицы
        mat[firstVert-1][secondVert-1] = weight;

    }
}





