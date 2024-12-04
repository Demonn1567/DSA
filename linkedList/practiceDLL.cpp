#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;
    Node* prev;

    Node(int data) {
        value = data;
        next = prev = NULL;
    }
};

class DLL {
    public:
    Node* head;

    DLL() {
        head = NULL;
    }
    //insertion
    void insertAtStart(int value) {
        Node* n1 = new Node(value);
        if(!head) head = n1;
        else {
            n1->next = head;
            head->prev = n1;
            head = n1;
        }
    }

    void insertAtEnd(int value) {
        Node* n1 = new Node(value);
        if(!head) head = n1;
        else {
            Node* temp = head;
            while(temp->next!=NULL) {
                temp = temp->next;
            }
            temp->next = n1;
            n1->prev = temp;
            n1->next = NULL;
        }
    }
    void insertAtPosition(int position, int value) {
        Node* n1 = new Node(value);
        if(position==1) {
            if(!head) {
                head = n1;
            }
            else {
                n1->next = head;
                head->prev = n1;
                head=  n1;
            }
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
            while(currentPosition < position - 1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp) {
                if(temp->next==NULL) {
                    temp->next = n1;
                    n1->prev = temp;
                    n1->next = NULL;
                }
                else {
                    n1->next = temp->next;
                    temp->next = n1;
                    n1->next->prev = n1;
                    n1->prev = temp;
                }
            }
        }
    }

    void insertElementBefore(int elementBefore, int value) {
        Node* n1 = new Node(value);
        if(head->value == elementBefore) {
            n1->next = head;
            head->prev = n1;
            head = n1;
        }
        else {
            Node* temp = head;
            while(temp->next!=NULL) {
                if(temp->next->value == elementBefore) {
                    n1->next = temp->next;
                    temp->next = n1;
                    n1->next->prev = n1;
                    n1->prev = temp;
                    return;
                }
                temp = temp->next;
            }
            cout<<"Invalid element";
        }
    }

    //deletion
    void deleteFromStart() {
        if(!head) return;

        Node* temp = head;
        head = head->next; 
        head->prev = NULL;
    }

    void deleteFromEnd() {
        if(!head) return;

        Node* temp = head;
        while(temp->next->next!=NULL) {
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = NULL;
        delete temp2;
    }

    void deleteFromPosition(int position) {
        if(!head) return;
        if(position==1) {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
            while(currentPosition < position-1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp) {
                if(temp->next->next==NULL) {
                    Node* temp1 = temp->next;
                    temp->next = NULL;
                    delete temp1;
                }
                else {
                    Node* temp2 = temp->next;
                    temp->next = temp->next->next;
                    temp->next->prev = temp;
                    delete temp2;
                }
            }
        }
    }

    void deleteElement(int element) {
        if(!head) return;
        if(head->value == element) {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
        else {
            Node* temp2 = head;
            while(temp2->next->value!=element) {
                temp2 = temp2->next;
            }
            if(temp2->next->next==NULL) {
                temp2->next = NULL;
            }
            else {
                temp2->next = temp2->next->next;
                temp2->next->prev = temp2;
            }

        }
    }




    void traverse() {
        if(!head)  {
            cout<<"Linked List Empty";
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
    dl1.insertAtEnd(5);
    dl1.insertAtStart(4);
    dl1.insertAtEnd(6);
    dl1.insertAtEnd(7);
    dl1.insertAtPosition(5,3);
    dl1.insertElementBefore(3,0);
    dl1.deleteElement(0);

    dl1.traverse();
    return 0;
}