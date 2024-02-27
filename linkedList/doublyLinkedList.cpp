#include <iostream>

using namespace std;

class Node {
    public:
    Node* next;
    Node* prev;
    int value;

    Node(int data) {
        value = data;
        next = prev = NULL;
    }
};

class DLL {
    public:
    Node* head;
    Node* tail;

    DLL() {
        head = tail = NULL;
    }
    void insertAtEnd(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = tail = n1;
        }
        else {
            tail->next = n1;
            n1->prev = tail;
            tail = n1;
        }
    }
    void insertAtStart(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = tail = n1;
        }
        else {
            n1->next = head;
            head->prev = n1;
            head = n1;
        }
    }
    void traverse() {
        if(!head) {
            cout<<"Linked list is empty";
            return;
        }
        Node* temp = head;
        while(temp) {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
    }
};

int main() {
    DLL dl1;
    dl1.insertAtEnd(10);
    dl1.insertAtEnd(20);
    dl1.insertAtEnd(30);
    dl1.insertAtEnd(40);
    dl1.insertAtStart(5);
    dl1.traverse();
    return 0;
}