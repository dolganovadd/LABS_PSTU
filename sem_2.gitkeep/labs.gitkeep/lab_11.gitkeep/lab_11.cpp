#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* prev;
    Node* next;

    Node(string data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    void append(string data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
            new_node->prev = current;
        }
    }

    void deleteNode(string key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                if (current == head) {
                    head = current->next;
                }
                delete current;
                break;
            }
            current = current->next;
        }
    }

    void insertAtPosition(string data, int position) {
        Node* new_node = new Node(data);
        if (position == 0) {
            new_node->next = head;
            if (head != nullptr) {
                head->prev = new_node;
            }
            head = new_node;
        }
        else {
            Node* current = head;
            for (int i = 0; i < position - 1 && current != nullptr; i++) {
                current = current->next;
            }
            if (current == nullptr) {
                cout << "Position out of range" << endl;
            }
            else {
                new_node->next = current->next;
                new_node->prev = current;
                if (current->next != nullptr) {
                    current->next->prev = new_node;
                }
                current->next = new_node;
            }
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.append("A");
    dll.append("B");
    dll.append("C");
    dll.append("D");

    cout << "List: ";
    dll.printList();

    dll.deleteNode("B");
    cout << "After deleting 'B': ";
    dll.printList();

    dll.insertAtPosition("X", 2);
    cout << "After inserting 'X' at position 2: ";
    dll.printList();

    return 0;
}