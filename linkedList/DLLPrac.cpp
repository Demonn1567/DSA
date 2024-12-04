#include <iostream>
using namespace std;


class Node {
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int data) {
        val = data;
        next = prev = NULL;

    }
};

class DLL {
    public:
    Node* head;

    DLL() {
        head = NULL;
    }

    void insertAtStart(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = n1;
            return;
        }
        n1->next = head;
        head->prev = n1;
        head = n1;
    }

    void insertAtEnd(int value) {
        Node* n1 = new Node(value);
        if(!head)  {
            head = n1;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        if(temp) {
            temp->next = n1;
            n1->prev = temp;
            n1->next = NULL;
        }
    }

    void insertAtPosition(int value, int position) {
        Node* n1 = new Node(value);
        if(position==1) {
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
            int currentPosition = 1;
            Node* temp =head;
            while(temp->next!=NULL && currentPosition<position-1) {
                currentPosition++;
                temp= temp->next;
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

    void deleteFromStart() {
        if(!head || head->next==NULL) return;

        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }

    void deleteFromEnd() {
        if(!head || head->next==NULL) return;

        Node* temp = head;
        while(temp->next->next!=NULL) {
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        temp->next = NULL;
        temp2->prev = NULL;
        delete temp2;
    }

    void deleteFromPosition(int position) {
        if(!head || head->next==NULL) return;

        if(position==1) {
            Node* temp1 = head;
            head = head->next;
            head->prev = NULL;
            temp1->next = NULL;
            delete temp1;
        }
        else {
            int currentPosition =1;
            Node* temp = head;
            while(currentPosition<position-1 && temp) {
                currentPosition++;
                temp = temp->next;
            }
            if(temp->next->next==NULL) {
                Node* temp2 = temp->next;
                temp->next =NULL;
                temp2->prev = NULL;
                delete temp2;
            }
            else {
                Node* temp3 = temp->next;
                temp->next = temp->next->next;
                temp3->prev = NULL;
                delete temp3;
            }
        }
    }

    void deleteElement(int element) {
        if (!head) return;

        // Case 1: Deleting the head node
        if (head->val == element) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = NULL;
            }
            delete temp;
            return;
        }

        // Case 2: Deleting a non-head node
        Node* temp = head;
        while (temp->next && temp->next->val != element) {
            temp = temp->next;
        }

        // If element was not found, return
        if (!temp->next) return;

        Node* nodeToDelete = temp->next;

        // If nodeToDelete is the last node
        if (nodeToDelete->next == NULL) {
            temp->next = NULL;
        } else {
            // Node to delete is in the middle
            temp->next = nodeToDelete->next;
            nodeToDelete->next->prev = temp;
        }

        delete nodeToDelete;
    }



    void traverse() {
        if(!head) {
            cout<<"List Empty";
            return;
        }
        Node* temp = head;
        while(temp!=NULL) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }

};


int main() {
    DLL dl1;

    dl1.insertAtStart(2);
    dl1.insertAtEnd(4);
    dl1.insertAtEnd(6);
    dl1.insertAtStart(0);
    dl1.insertAtPosition(8, 5);
    dl1.deleteFromStart();
    dl1.deleteFromEnd();
    //dl1.deleteFromPosition(3);
    dl1.deleteElement(2);

    dl1.traverse();

    return 0;
}
