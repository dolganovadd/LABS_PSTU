# **Лабораторная работа №11 "Информационные динамические структуры".**

# Блок - схемы 

>linked list

![](https://psv4.userapi.com/c237331/u272768864/docs/d58/db30ed278e88/linked_list.png?extra=JjnEiVWsX47IiHN1bW6m7QgCoSdaorTlLYJcIxjQhNPJGHw7f0POWGOjR8Dx6Q47_nz68RIeEh_pkZXFcPzK1MdttNwPH8xHidV7qXQffdZ_QNd4_jcAYRYv3VQAh8P-mw5S25bRs4xZeJVanh8WQxIQWRw)

>double-linked list

![](https://psv4.userapi.com/c237331/u272768864/docs/d60/9b9c821263f9/double_-_linked_list.png?extra=vtOsCxLAmi4VNIQds0kL7MlWDPWRqoOimRIlHBAHDdgeRtp-NGRrAh-RiyY4rJyip5R_-_aWXxLyhP0TJYGJc3ISD7jUwjsZFGWj6h5y9eizYIssOdZ4CtEUGBv-cdSiBETksrJr-0w2jxUlbcrbx45IvrU)

>stack

![](https://psv4.userapi.com/c237331/u272768864/docs/d7/5689d272e6fd/stack.png?extra=sV1jkrqAv6n0LPlG2diwBa5-dDU_2OBoVUMEB9WqYUNQrQw3D6i-EIm8vyh5L2NFP7GboOYFjY_OP_W23YbUvSbPaf6bsPRM47_GUfO4cvRLq6ldsNiEdqUiibG9A3Djxk4Ljtj8cVJFasLt4W2y6SwnuMw)

>queue

![](https://psv4.userapi.com/c237331/u272768864/docs/d34/59d5aa3e517b/queue.png?extra=0HNGXc5Bg2d88hGxguvTL7jvY_eClafBNjHZgH3IHtuziP1NWFF6BSVAdVWwQJYdG8F3WUNBmVlQpFxh58xKP8zfO8Yjkx1v20PDafFvf0ZDZjn8Tiba_iz_SaRlDtS-yXFjTAnpbgLrnga3nDJyYyuOaPA)

# Код программы 

> linked list

```cpp
#include <iostream>
#include <cstring>

using namespace std;

struct Node {
	char data;
	Node* pointer_to_next_node = nullptr;
};

struct  List {
	Node* head_node = nullptr; 
	Node* tail_node = nullptr; 
};



void pushBack(List& list, const char& data) {
	Node* new_node = new Node; 
	new_node->data = data; 

	if (list.head_node == nullptr) { 
		list.head_node = new_node;
		list.tail_node = new_node;
	}
	else {
		
		list.tail_node->pointer_to_next_node = new_node;
		
		list.tail_node = new_node;
	}
}


void remove(List& list, char& key) {
	Node* current_node = new Node; 
	current_node->pointer_to_next_node = list.head_node; 
	bool flag = false;
	while (current_node->pointer_to_next_node != nullptr) 
	{
		if (current_node->pointer_to_next_node->data == key) 
		{
			Node* tmp; 
			if (current_node->pointer_to_next_node == list.head_node) 
			{
				tmp = list.head_node; 
				list.head_node = list.head_node->pointer_to_next_node; 
				current_node->pointer_to_next_node = list.head_node; 
			}
			else if (current_node->pointer_to_next_node == list.tail_node) 
			{
				tmp = list.tail_node; 
				list.tail_node = current_node; 
				current_node->pointer_to_next_node = nullptr; 
			}
			else {
				tmp = current_node->pointer_to_next_node; 
				current_node->pointer_to_next_node = tmp->pointer_to_next_node; 

			}
			delete tmp;
		}
		else {
			current_node = current_node->pointer_to_next_node; 
			flag = true;
		}
	}
	if (!flag) 
	{
		delete current_node; 
	}
}

void popFront(List& list) {
	
	if (list.head_node == nullptr) {
		return;
	}
	
	Node* remove = list.head_node;
	
	list.head_node = list.head_node->pointer_to_next_node;

	if (remove == list.tail_node) {
		list.tail_node = nullptr;
	}
	delete remove;
}

void print(List& list)
{
	
	Node* current_node = list.head_node;
	if (current_node == nullptr) 
	{
		cout << "Ваш список оказался пустым" << endl;
	}
	else {
		cout << "Ваш список: " << endl;
		while (current_node != nullptr) 
		{
			cout << current_node->data << " "; 
			current_node = current_node->pointer_to_next_node; 
		}
		cout << endl;
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
	
	Node* current_node = list.head_node;
	while (current_node != nullptr) {
		
		cout << current_node->data << ' ';
		
		current_node = current_node->pointer_to_next_node;
	}
	cout << endl;
	print(list);
	char key;
	cout << "Введите символ, который нужно удалить" << endl;
	cin >> key;
	remove(list, key);
	print(list);
	cout << "Сколько элементов добавить в конец списка: " << endl;
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
```

>double-linked list

```cpp
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
```

>stack

```cpp
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

```

>queue

```cpp
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
```
