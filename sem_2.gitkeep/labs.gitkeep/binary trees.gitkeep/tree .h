#ifndef TREE_H
#define TREE_H

#include <QString>

using namespace std;
//14
//8,3,10,1,4,9,11,19,17,25,16,18,23,27

// Структура узла: данные, левый/правый указатели на потомков, номер узла, начальные координаты, ссылающиеся на координаты корня
struct Node{
    int data = 0;
    Node *left = 0;
    Node *right = 0;
    int num = 0;
    int x = 356;
    int y;
};

class Tree
{
    int min = 100000;
public:
    int count = 0; // Общее количество узлов
    Node *root = NULL; // Начальный узел, от которого будем растить наше деревцо

    void init(int x){
        root =new Node; // память под узел
        root->data = x; // присваивание данных
        if (x < min) min = x;
    }

    // Рекурсивное добавление узла с рекурсивным расчетом координат
    Node *addNode(int x, Node *tree, int z, int y, int h) {
        if (tree == NULL) { // Если дерева нет, то формируем корень
            tree =new Node; // память под узел
            tree->data = x;   // поле данных
            tree->num = ++count; // Увеличение числа узлов
            tree->x = z;
            tree->y = y;

            if (x < min) min = x;
        }else  if (x < tree->data){   // условие добавление левого потомка
            tree->left = addNode(x,tree->left, z-(h),y+85,h/2);
        }
        else{    // условие добавление правого потомка
            tree->right = addNode(x,tree->right, z+(h),y+85,h/2);
        }
        return(tree);
    }

    //    Рекурсивное удаление узла от передаваемого указателя
    void deletNodes(Node *tree) {
        if(tree!=NULL) {
            count--;
            deletNodes(tree->left);
            deletNodes(tree->right);
            delete tree;
        }
    }
    // Поиск нужного узла для удаления и передача указателя для рекурсивного удаления
    void delNodes(int data,Node *tree){

        if (tree != NULL) {
            if (tree->data == data) {deletNodes(tree);tree = NULL; return;}
            if (tree->data > data) {delNodes(data,tree->left); tree->left = NULL;}
            if (tree->data <data) {delNodes(data,tree->right); tree->right = NULL;}
        }
    }

    // Показ дерева (отличия для 3 видов обхода заключается в перемещении функции печати до/между/после вызова рекурсии)
    void showTree(Node *tree) {
        if (tree != NULL) {
            showTree(tree->left);
            printf("%i %i\n", tree->num, tree->data);
            showTree(tree->right);
        }
    }
    // Возвращение среднего арифметического
    double getMin(){ return min;}
    // Добавление узлов, перечисленных в строке через ","
    void arrNodes(QString a, Node *tree){
        int cnt = 0;
        QString str = "";
        for (int i(1); i < a.size(); i++){
            str+=a[i-1];
            if (a[i]==','){
                addNode(str.toInt(),tree, 356,0,200);
                str.clear();
                i++;
            }
        }
        str+=a[a.size()-1];
        addNode(str.toInt(),tree, 356,0,200);
    }
    Tree(){};
};

#endif // TREE_H
