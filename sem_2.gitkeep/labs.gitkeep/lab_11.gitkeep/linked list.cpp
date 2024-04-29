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