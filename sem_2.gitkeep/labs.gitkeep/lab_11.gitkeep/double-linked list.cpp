#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
    char data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
};

void pushBack(List& list, const char& data)
{
    Node* new_node = new Node;
    new_node->data = data;
    if (list.head == nullptr)
    {

        list.head = new_node;
        list.tail = new_node;
    }
    else {
        list.tail->next = new_node;
        new_node->prev = list.tail;
        list.tail = new_node;
    }
}

void pushFront(List& list, const char& data) {
    Node* new_node = new Node;
    new_node->data = data;
    if (list.head == nullptr)
    {

        list.head = new_node;
        list.tail = new_node;
    }
    else {
        new_node->next = list.head;
        list.head->prev = new_node;
        list.head = new_node;
    }
}

void print(List& list) {
    Node* current_node = list.head;
    if (current_node == nullptr)
    {
        cout << "Ваш список оказался пустым" << endl;
    }
    else {
        cout << "Ваш список: " << endl;
        while (current_node != nullptr)
        {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
}


void remove(List& list, char& key) {
    Node* current_node = new Node;
    current_node->next = list.head;
    while (current_node != nullptr)
    {
        Node* tmp = current_node;
        current_node = current_node->next;
        if (tmp->data == key)
        {
            if (tmp->next == nullptr && tmp->prev == nullptr)
            {

                list.head = nullptr;
                list.tail = nullptr;
            }
            else if (tmp == list.head)
            {
                list.head = tmp->next;
                list.head->prev = nullptr;
            }
            else if (tmp == list.tail)
            {
                list.tail = tmp->prev;
                list.tail->next = nullptr;
            }
            else {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
            }

            delete tmp;
        }
    }
}

int main() {
    system("chcp 1251");
    int n;
    cout << "Введите количество элементов списка: " << endl;
    cin >> n;
    List list;
    for (int i = 0; i < n; i++) {
        char Char;
        cout << "Введите символ: " << endl;
        cin >> Char;
        pushBack(list, Char);
    }
    cout << endl;
    print(list);
    char key;
    cout << "Введите символ, который нужно удалить: " << endl;
    cin >> key;
    remove(list, key);
    print(list);
    cout << "Введите сколько еще символов вы хотите добавить в конец списка: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char Char;
        cout << "Введите символ: " << endl;
        cin >> Char;
        pushBack(list, Char);
    }
    cout << endl;
    print(list);
}