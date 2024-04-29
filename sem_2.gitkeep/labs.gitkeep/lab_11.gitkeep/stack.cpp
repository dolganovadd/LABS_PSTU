#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node* next = nullptr;
};

struct Stack
{
    Node* head = nullptr;
    int size = 0;

    void pushFront(char data)
    {
        Node* node = new Node;
        node->data = data;

        if (head == nullptr)
            head = node;
        else
        {
            node->next = head;
            head = node;
        }

        size++;
    }

    void pushBack(char data)
    {
        Stack* buffer = new Stack;

        for (int i = 0; i < size; i++)
        {
            buffer->pushFront(head->data);


            Node* tmp = head;
            head = head->next;
            delete tmp;
        }

        size = 0;
        pushFront(data);
        Node* current = buffer->head;

        for (int i = 0; i < buffer->size; i++)
        {
            pushFront(current->data);
            current = current->next;
        }

        buffer->Clear();
        delete buffer;
    }

    void print()
    {
        if (size == 0)
            cout << "Ваш стек пуст" << endl;
        else
        {
            cout << "Ваш стек:" << endl;

            Node* current = head;

            for (int i = 0; i < size; i++)
            {
                cout << current->data << " ";
                current = current->next;
            }

            cout << endl;
        }
    }
    void remove(char key)
    {
        Stack* buffer = new Stack;

        for (int i = 0; i < size; i++)
        {
            if (head->data != key)
                buffer->pushFront(head->data);


            Node* tmp = head;
            head = head->next;
            delete tmp;
        }

        size = 0;
        Node* current = buffer->head;

        for (int i = 0; i < buffer->size; i++)
        {

            pushFront(current->data);
            current = current->next;
        }

        buffer->Clear();
        delete buffer;
    }

    void Clear()
    {
        for (int i = 0; i < size; i++)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }

        head = nullptr;

        size = 0;
    }
};


int main()
{
    system("chcp 1251");
    int n;
    cout << "Введите количество элементов стека: " << endl;
    cin >> n;
    Stack* stack = new Stack;
    for (int i = 0; i < n; i++) {
        char Char;
        cout << "Введите символ: " << endl;
        cin >> Char;
        stack->pushBack(Char);
    }
    cout << endl;
    stack->print();
    char key;
    cout << "Введите какой элемент стека нужно удалить: " << endl;
    cin >> key;
    stack->remove(key);
    stack->print();
    cout << "Введите сколько элементов нужно добавить в стек: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char Char;
        cout << "Введите символ: " << endl;
        cin >> Char;
        stack->pushBack(Char);
    }
    cout << endl;
    stack->print();
}

