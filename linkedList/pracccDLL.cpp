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
    
    //insertion operations
    void insertAtStart(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = n1;
        }
        else {
            n1->next = head;
            head->prev = n1;
            head=  n1;
        }
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
            n1->prev = temp;
            n1->next = NULL;
        }
    }

    void insertAtPosition(int position, int value) {
        Node* n1 = new Node(value);
        if(position ==1) {
            if(!head) {
                head = n1;
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
            while(currentPosition < position -1  && temp) {
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
                    n1->prev = temp;
                    temp->next->prev = n1;
                    temp->next = n1;
                }
            }
        }
    }

    void insertBeforeElement(int elementBefore, int value) {
        Node* n1 = new Node(value);
        if(head->value == elementBefore) {
            n1->next = head;
            head->prev = n1;
            head = n1;
        }
        else {
            Node* temp = head;
            while(temp->next->value!=elementBefore) {
                temp = temp->next;
            }
            n1->next = temp->next;
            n1->prev = temp;
            temp->next->prev = n1;
            temp->next = n1;
            return;
        }
    }

    void deleteAtStart() {
        if(!head) return;

        Node* temp = head;
        head=  head->next;
        delete temp;
        head->prev = NULL;
    }

    void deleteAtEnd() {
        if(!head) return;

        Node* temp = head;
        while(temp->next->next!=NULL) {
            temp = temp->next;
        }
        Node* temp4 = temp->next;
        temp->next = NULL;
        temp4->next = NULL;
    }

    void deleteAtPosition(int position) {
        if(!head) return;

        if(position == 1) {
            Node* temp = head;
            head  =head->next;
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
                    temp->next = NULL;
                }
                else {
                    temp->next = temp->next->next;
                    temp->next->prev = temp;
                }
            }
        }
    }

    void deleteElement(int element) {
        if(!head) return;
        if(head->value==element) {
            head = head->next;
        }
        else {
            Node* temp = head;
            while(temp->next->value!=element) {
                temp = temp->next;
            }
            if(temp->next->next==NULL) {
                temp->next = NULL;
            }
            else {
                temp->next = temp->next->next;
                temp->next->prev = temp;
            }
        }
    }

    



    void traverse() {
        if(!head) {
            return;
        }
        Node* temp = head;
        while(temp) {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
    }

};

Node* reverseDLL(Node* head) {
        if(!head) return head;

        Node* back  =NULL;
        Node* current = head;
        while(current) {
            back = current->prev;
            current->prev = current->next;

            current->next = back;
            current = current->prev;
        }
        return back->prev;
    }


int main() {
    DLL dl1;
    dl1.insertAtStart(4);
    dl1.insertAtStart(3);
    dl1.insertAtStart(2);
    dl1.insertAtStart(1);
    dl1.insertAtEnd(5);
    dl1.insertAtPosition(6,0);
    dl1.insertBeforeElement(0,-1);
    dl1.deleteAtEnd();
    dl1.deleteAtPosition(6);
    dl1.deleteElement(5);
    dl1.head = reverseDLL(dl1.head);
    

    //dl1.traverse();

    return 0;
}