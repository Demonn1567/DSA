#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int data) {
        value = data;
        next = NULL;
    }
};

class CSLL {
    public:
    Node* head;

    CSLL() {
        head = NULL;
    }
    void insertAtEnd(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = n1;
        }
        else {
            Node* temp = head;
            while(temp->next!=NULL) {
                temp = temp->next;
            }
            temp->next = n1;
            n1->next = head;
        }
    }

    

};