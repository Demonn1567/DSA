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

class SLL {
    public:
    Node* head;

    SLL() {
        head = NULL;
    }
    void deleteFromStart() {
        if(!head) {
            cout<<"Linked List empty";
            return;
        }
        
        head = head->next;
        
    }
    void deleteFromEnd() {
        if(!head) {
            cout<<"Linked List empty";
            return;
        }
        if(head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next !=NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void deleteFromPosition(int position) {
        if(!head) {
            cout<<"Linked List empty";
            return;
        }
        if(position==1) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node* temp = head;
            int currentPosition =1;
            while(currentPosition<position-1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp) {
                temp->next = temp->next->next;
            }
            else {
                cout<<"Invalid Position";
            }
        }
}

    void deleteElement(int element) {
        if(!head) {
            cout<<"Linked list empty";
            return;
        }
        if(head->value == element) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node* temp = head;
            while(temp->next->value!=element && temp->next!=NULL) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            
            
            
            
        }
    }

    void insertAtStart(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = n1;
        }
        else {
            n1->next = head;
            head = n1;
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
                head = n1;
            }
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
            while(currentPosition < position-1 && temp!=NULL) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp) {
                n1->next = temp->next;
                temp->next = n1;
            }
        }
    }
    //insert an element before a given element in the linked list
    void insertBeforeElement(int elementBefore, int value) {
        Node* n1 = new Node(value);
        if(head->value == elementBefore) {
            n1->next = head;
            head = n1;
        }
        else {
            Node* temp = head;
            while(temp->next!=NULL)  {
                if(temp->next->value == elementBefore) {
                    n1->next = temp->next;
                    temp->next = n1;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    void fun1(Node* head) {
        if(!head) return;

        fun1(head->next);
        cout<<head->value<<" ";
    }

    

    void displayNodes() {
        if(!head) {
            cout<<"Linked List empty";
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
    SLL sl1;
    sl1.insertAtStart(10);
    sl1.insertAtStart(8);
    sl1.insertAtStart(6);
    sl1.insertAtStart(4);
    sl1.insertAtStart(2);
    sl1.insertAtEnd(12);
    sl1.insertAtPosition(7,0);
    sl1.insertBeforeElement(0,1);
    sl1.deleteElement(0);

    sl1.displayNodes();
    //sl1.fun1(sl1.head);
    
    
    return 0;
}