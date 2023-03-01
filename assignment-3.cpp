#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void createNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtLast(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAtPosition(int value, int position) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* previous = head;
            for (int i = 1; i < position ; i++) {
                previous = previous->next;
            }
            newNode->next = previous->next;
            previous->next = newNode;
        }
    }

    void displayList() {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            Node* current = head;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    LinkedList myList;
    myList.createNode(1);
    myList.createNode(2);
    myList.createNode(4);
    myList.createNode(5);

    myList.insertAtBeginning(0);
    myList.displayList(); // 0 1 2 4 5

    myList.insertAtLast(6);
    myList.displayList(); // 0 1 2 4 5 6

    myList.insertAtPosition(3, 3);
    myList.displayList(); // 0 1 3 2 4 5 6

    return 0;
}

