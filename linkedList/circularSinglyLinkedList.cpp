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
            head->next = head;
        }
        else {
            Node* temp = head;
            while(temp->next!=head) {
                temp = temp->next;
            }
            temp->next = n1;
            n1->next = head;
        }
    }

    void insertAtStart(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = n1;
            head->next = head;
        }
        else{
            
            Node* temp = head;
            while(temp->next!=head) {
                temp = temp->next;
            }
            temp->next = n1;
            n1->next = head;
            head = n1;
        }
    }
    
    void insertAtPosition(int position,int value) 
    {
        Node* n1 = new Node(value);
        if(position == 1) {
            if(!head) {
                head = n1;
                head->next = head;
            }
            else {
                Node* temp = head;
                while(temp->next!=head){
                    temp = temp->next;
                }
                temp->next = n1;
                n1->next = head;
                head = n1;
            }
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
            while(currentPosition < position -1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp) {
                if(temp->next == head) {
                    temp->next = n1;
                    n1->next = head;
                }
                else {
                    n1->next = temp->next;
                    temp->next = n1;
                }
            }
        }
    }

    //deletion operations
    void deleteAtStart() {
        if(!head) {
            cout<<"Linked list empty";
            return;
        }
        
        Node* temp = head;
        while(temp->next!=head) {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
    }

    void deleteAtEnd() {
        if(!head) {
            cout<<"Linked list empty";
            return;
        }
        Node* temp = head;
        while(temp->next->next!=head) {
            temp = temp->next;
        }
        temp->next = head;
    }

    void deleteFromPosition(int position) {
        if(!head) {
            cout<<"Linked list empty";
            return;
        }
        if(position == 1) {
            
            Node* temp = head;
            while(temp->next!=head) {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
        }
        else {
            Node* temp = head;
            int currentPosition =1;
            while(currentPosition < position -1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp) {
                if(temp->next->next==head) {
                    temp->next = head;
                }
                else {
                    temp->next = temp->next->next;
                }
            }
        }
    }

    void traverse() {
        if(!head) {
            cout<<"Linked list empty";
            return;
        }
        Node* temp = head;
        while(temp->next!=head) {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
        cout<<temp->value;
    }

};

int main() {
    CSLL csl1;
    csl1.insertAtEnd(2);
    csl1.insertAtEnd(4);
    csl1.insertAtEnd(6);
    csl1.insertAtEnd(8);
    csl1.insertAtStart(0);
    csl1.insertAtPosition(6,-1);
    //csl1.deleteAtStart();
    //csl1.deleteAtEnd();
    csl1.deleteFromPosition(6);

    
    csl1.traverse();


    return 0;

}