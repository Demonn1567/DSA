//applying all the operations on a linked list
//we take up elements for the main linked list from the avail list, also known as heap.
#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = NULL;
    }
};

class SLL{
    public:
    Node* head;
    Node* tail;

    SLL() {
        head = tail = NULL;
    }
    void insertAtEnd(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = tail = n1;
            return;
        }
        tail->next = n1;
        tail = n1;
    }
    void insertAtStart(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = tail = n1;
            return;
        }
        n1->next = head;
        head = n1;
    }
    void traverseList() {
        if(!head) {
            cout<<"linked list is empty";
            return;
        }
        Node* temp = head;
        while(temp) {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
    }
    void deleteFromStart() {
        if(!head) {
            cout<<"linked list is empty";
            return;
        }
        head = head->next;
    }
    void deleteFromEnd() {
        if(!head) {
            cout<<"linked list is empty";
            return;
        }
        if(head == tail) {
            delete head;
            head = tail = NULL;
        }
        Node* temp = head;
        while(temp->next!=tail) {
            temp = temp->next;
        }
        delete tail;
        temp->next = NULL;
        tail = temp;
    }
    void insertAtPosition(int position, int value) {
        Node* n1 = new Node(value);
        if(position==1) {
            if(!head) {
                head = tail = n1;
                return;
            }
            n1->next = head;
            head=n1;
            return;
        }
        Node* temp = head;
        int currentPosition=1;
        while(currentPosition<position-1&& temp) {
            temp = temp->next;
            currentPosition++;
        }
        if(temp) {
            if(tail==temp) {
                tail->next = n1;
                tail = n1;
            }
            else {
                n1->next = temp->next;
                temp->next = n1;
            }
        }
    }
    void deleteFromPosition(int position) {
        if(!head) {
            cout<<"linked list empty";
            return;
        }
        if(position==1) {
            head = head->next;
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
            while(currentPosition<position-1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp) {
                temp->next = temp->next->next;
            }
        }
    }
};

int main() {
    SLL l1;
    l1.insertAtEnd(10);
    l1.insertAtEnd(20);
    l1.insertAtEnd(30);
    l1.insertAtEnd(40);
    l1.insertAtStart(5);
    l1.deleteFromPosition(5);

}