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
    void insertAtPosition(int position, int value) {
        Node* n1 = new Node(value);
        if(position == 1) {
            if(!head) {
                head = tail = n1;
            }
            else {
                n1->next = head;
                head->prev = n1;
                head = n1;
            }
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
            while(currentPosition < position-1&& temp) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp && temp->next) {
                n1->next = temp->next;
                temp->next->prev = n1;
                n1->prev = temp;
                temp->next = n1;
            }
            else {
                tail = n1;
                n1->prev = temp;
                temp->next = n1;
            }
        }
    }
    void deleteAtStart() {
        if(!head) {
            cout<<"Linked list is empty";
            return;
        }
        head = head->next;
        head->prev = NULL;
    }
    void deleteAtEnd() {
        if(!head) {
            cout<<"Linked list is empty";
            return;
        }
        Node* temp = head;
        while(temp->next->next !=NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
    }
    void deleteFromPosition(int position) {
        if(!head) {
            cout<<"Linked list is empty";
            return;
        }
        if(position == 1) {
            head = head->next;
            head->prev = NULL;
        }
        else 
        {
            Node* temp = head;
            int currentPosition = 1;
            while(currentPosition < position -1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp && temp->next!=NULL) {
                if(temp->next->next == NULL) {
                    temp->next = NULL;
                    tail = temp;
                }
                else {
                    temp->next = temp->next->next;
                    temp->next->prev = temp;
                }
            }
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
    dl1.insertAtPosition(6, 2);
    dl1.deleteFromPosition(3);
    dl1.traverse();
    return 0;
}