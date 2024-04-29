#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data; 
    Node<T>* next; 
};

template <typename T>
struct Queue
{
    int size; 
    Node<T>* head; 
    Node<T>* tail; 
};

template <typename T>
void newQueue(Queue<T>& q, int n) {
    T a;
    cout << "Введите элемент: ";
    cin >> a;
    initQueue(q, a); 
    for (int i = 2; i <= n; i++) {
        cout << "Введите элемент: ";
        cin >> a;
        push(q, a); 
    }
}

template <typename T>
void initQueue(Queue<T>& q, const T& value) {
    Node<T>* new_Node = new Node<T>(); 
    new_Node->data = value; 
    q.head = new_Node; 
    q.tail = new_Node; 
    q.size = 1; 
}

template <typename T>
void push(Queue<T>& q, const T& value) {
    Node<T>* new_Node = new Node<T>(); 
    q.size++;
    new_Node->data = value; 
    new_Node->next = nullptr;  
    q.tail->next = new_Node; 
    q.tail = new_Node; 
}

template <typename T>
void printQueue(Queue<T>& q) {
    Node<T>* tmp = q.head; 
    cout << "начало -> ";
    while (tmp != nullptr) 
    {
        cout << tmp->data << " -> "; 
        tmp = tmp->next; 
    }
    cout << "конец" << endl;
}

template <typename T>
void pop(Queue<T>& q)
{
    Node<T>* tmp = q.head; 
    q.head = q.head->next;  
    q.size--; 
    delete tmp; 
}

template <typename T>
void deleteKey(Queue<T>& q, T k)
{
    int i = 1;
    while (i <= q.size) 
    {
        if (q.head->data == k) 
        {
            pop(q); 
        }
        else {
            push(q, q.head->data);
            pop(q);
            i++;
        }
    }
}

template <typename T>
void insert(Queue<T>& q, int count, int number)
{
    int i = 1;
    while (i < number) 
    {
        push(q, q.head->data);
        pop(q);
        i++;
    }
    T a;
    for (int j = 1; j <= count; j++) {
        cout << "Введите элемент для добавления: ";
        cin >> a;
        push(q, a); 
    }
    for (i; i <= q.size - count; i++) 
    {
        push(q, q.head->data);
        pop(q); 
    }
}

template <typename T>
void deleteQueue(Queue<T>& q)
{
    while (q.head->next != nullptr) 
    {
        pop(q); 
    }
    Node<T>* tmp = q.head;
    q.head = nullptr;
    q.size--;
    delete tmp; 
}

int main()
{
    system("chcp 1251");
    Queue<char> q;
    int n;

    do
    {
        cout << "Введите количество элементов в очереди: ";
        cin >> n;
    } while (n <= 0); 

    newQueue(q, n); 
    cout << endl;
    printQueue(q); 

    cout << endl << "Введите ключ элемента, который необходимо удалять: ";
    char key;
    cin >> key;

    deleteKey(q, key);
    cout << endl;
    printQueue(q);

    int number = q.size + 1;
    cout << endl << "Введите количество элементов для добавления: ";
    int count;
    cin >> count;

    insert(q, count, number); 
    cout << endl;
    printQueue(q);

    cout << endl << "Очищение динамической памяти ...";
    deleteQueue(q);
    cout << "Завершено." << endl;
    printQueue(q);
    return 0;

}