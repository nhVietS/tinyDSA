#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class LinkedListInterface {
public:
    virtual void add(T data) = 0;
    virtual void printList() = 0;
};

template <typename T>
class LinkedList : public LinkedListInterface<T> {
    Node<T>* head;

public:
    LinkedList() {
        head = NULL;
    }

    virtual ~LinkedList() {
        Node<T>* current = head;
        Node<T>* next;

        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }

        head = NULL;
    }

    void add(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList() {
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList<int>* myList = new LinkedList<int>();
    myList->add(1);
    myList->add(2);
    myList->add(3);
    myList->printList();   // Should output: 1 2 3

    LinkedList<string>* myStringList = new LinkedList<string>();
    myStringList->add("Hello");
    myStringList->add("World");
    myStringList->printList();   // Should output: Hello World

    delete myList;
    delete myStringList;

    return 0;
}
