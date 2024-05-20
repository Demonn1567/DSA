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
    void insertAtStart(int value) {
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
            head = n1;
        }
    } 

    void insertAtEnd(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head=  n1;
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

    void insertAtPosition(int position, int value) {
        Node* n1 = new Node(value);
        if(position==1) {
            if(!head) {
                head = n1;
                head->next = head;
            }
            else {
                Node* temp = head;
                while(temp->next!=head) {
                    temp = temp->next;
                }
                temp->next  =n1;
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

    void insertBeforeElement(int elementBefore, int value) {
        Node* n1 = new Node(value);
            if(head->value == elementBefore) {
                Node* temp = head;
                while(temp->next!=head) {
                    temp = temp->next;
                }
                temp->next =n1;
                n1->next = head;
                head = n1;
            }
            else {
                Node* temp = head;
                while(temp->next->value!=elementBefore) {
                    temp = temp->next;
                }
                n1->next = temp->next;
                temp->next = n1;
            }
        }

    void deleteAtStart() {
        if(!head) {
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
            return;
        }
        Node* temp = head;
        while(temp->next->next!=head) {
            temp  = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = head;
        delete temp2;
    }

    void deleteAtPosition(int position) {
        if(!head) {
            return;
        }
        if(position==1) {
            Node* temp = head;
            while(temp->next!=head) {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
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

    void deleteElement(int element) {
        if(!head) {
            return;
        }
        if(head->value ==element) {
            Node* temp = head;
            while(temp->next!=head) {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
        }
        else {
            Node* temp = head;
            while(temp->next->value!=element) {
                temp = temp->next;
            }
            if(temp) {
                if(temp->next->next ==head) {
                    temp->next = head;
                }
                else {
                    temp->next = temp->next->next;
                }
            }
        }
    }

    Node* middleLinkedList(Node* head) {
        if(!head) return head;

        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL || fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    

    void traverse() {
        if(!head) return;

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
    csl1.insertAtStart(4);
    csl1.insertAtStart(3);
    csl1.insertAtStart(2);
    csl1.insertAtStart(1);
    csl1.insertAtEnd(5);
    csl1.insertAtPosition(6,0);
    csl1.insertBeforeElement(0,-1);
    csl1.deleteAtStart();
    csl1.deleteAtEnd();
    csl1.deleteAtPosition(5);
    csl1.deleteElement(5);


    csl1.traverse();
    return 0;
}