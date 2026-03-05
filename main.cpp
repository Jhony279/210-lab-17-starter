// COMSC-210 | Lab 17 | Johnathan Perez Baltazar

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void deleteNode(Node *&);
void insertNode(Node *&);
void insertNodeFront(Node *&);
void insertNodeEnd(Node *&);
void deleteList(Node *&);
Node * createList(int);

int main() {
    Node *head = createList(SIZE);

    output(head);
    deleteNode(head);
    insertNode(head);
    deleteList(head);
    insertNodeFront(head);
    insertNodeEnd(head);

    return 0;
}

Node * createList(int size) {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    return head;
}

void deleteNode(Node *&hd){
    // deleting a node
    Node * current = hd;
    cout << "Which node to delete? " << endl;
    output(hd);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = hd;
    Node *prev = hd;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(hd);
}

void insertNode(Node *&hd){
    // insert a node
    Node *current = hd;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    int entry;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = hd;
    Node *prev = hd;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(hd);
}

void deleteList(Node *&hd){
    // deleting the linked list
    Node * current = hd;
    while (current) {
        hd = current->next;
        delete current;
        current = hd;
    }
    hd = nullptr;
    output(hd);
}

void insertNodeFront(Node *&hd){
    // insert a node at the front of the list
    Node * newnode = new Node;
    cout << "What value to insert at the front? " << endl;
    int count = 1;
    int entry;
    while (newnode) {
        cout << "[" << count++ << "] " << newnode->value << endl;
        newnode = newnode->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    // insert the new node at the front of the list
    newnode->value = entry;
    newnode->next = hd;
    hd = newnode;
    output(hd);
}

void insertNodeEnd(Node *&hd){
    // insert a node at the end of the list
    Node * newnode = new Node;
    cout << "What value to insert at the end? " << endl;
    int count = 1;
    int entry;
    while (newnode) {
        cout << "[" << count++ << "] " << newnode->value << endl;
        newnode = newnode->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    newnode->value = entry;
    newnode->next = nullptr;

    if (!hd) { // if the list is empty, make the new node the head
        hd = newnode;
    } else { // otherwise, find the end of the list and append the new node
        Node * current = hd;
        while (current->next) {
            current = current->next;
        }
        current->next = newnode;
    }
    output(hd);
}

void output(Node * hd) {
    // output the linked list
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    // traverse the list and output each node's value
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}