#include <iostream>
using namespace std;

// Definition of the Node class
class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    if (*headRef != NULL)
        (*headRef)->prev = newNode;
    *headRef = newNode;
}

// Function to delete a node with given key
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with key " << key << " not found!" << endl;
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *headRef = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

// Function to traverse the list and print the data of each node
void traverse(Node* head) {
    cout << "The list is: ";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the program
int main() {
    Node* head = NULL;

    // Creating the list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Traversing the list
    traverse(head);

    // Deleting a node
    deleteNode(&head, 3);

    // Traversing the list again
    traverse(head);

    return 0;
}
