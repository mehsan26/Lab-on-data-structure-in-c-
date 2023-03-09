#include<iostream>
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
        } 
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
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

    void removeNode(int position) {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            Node* current = head;
            Node* previous = NULL;
            int count = 1;

            while (current != NULL && count != position) {
                previous = current;
                current = current->next;
                count++;
            }

            if (count == position && current != NULL) {
                if (previous == NULL) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                cout << "Element removed successfully" << endl;
            } else {
                cout << "Invalid position" << endl;
            }
        }
    }
};

int main() {
    LinkedList myList;
    myList.createNode(1);
    myList.createNode(2);
    myList.createNode(3);
    myList.createNode(4);
    myList.createNode(5);
    myList.createNode(5);
    myList.createNode(5);
    myList.createNode(5);
    myList.createNode(5);
    myList.createNode(5);
    
    myList.displayList(); // 1 2 3 4 5

    myList.removeNode(3);
    myList.displayList(); // 1 2 4 5

    myList.removeNode(1);
    myList.displayList(); // 2 4 5

    

    return 0;
}
