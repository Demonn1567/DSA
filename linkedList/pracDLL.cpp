#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int data) {
        value = data;
        prev = next = NULL;
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
        if (!head) {
            head = n1;
        }
        else {
            n1->next = head;
            head->prev = n1;
            head = n1;
        }
    }
    void insertAtEnd(int value) {
        Node* n1 = new Node(value);
        if (!head) {
            head = n1;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = n1;
            n1->prev = temp;
            n1->next = NULL;
        }
    }

    void insertAtPosition(int position, int value) {
        Node* n1 = new Node(value);
        if (position == 1) {
            if (!head) {
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
            while (currentPosition < position - 1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if (temp) {
                if (temp->next == NULL) {
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
        if (head->value == elementBefore) {
            n1->next = head;
            head->prev = n1;
            head = n1;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                if (temp->next->value == elementBefore) {
                    n1->next = temp->next;
                    n1->prev = temp;
                    temp->next->prev = n1;
                    temp->next = n1;
                    return;
                }
                temp = temp->next;
            }
            cout << "Invalid Element";
        }
    }

    //deletion operations
    void deleteFromStart() {
        if (!head) {
            cout << "Linked list empty";
            return;
        }
        head = head->next;
        head->prev = NULL;
        
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "Linked List Empty";
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void deleteFromPosition(int position) {
        if (!head) {
            cout << "Linked list empty";
            return;
        }
        if (position == 1) {
            head = head->next;
            if (head)
                head->prev = NULL;
            return;
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
            while (currentPosition < position - 1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if (temp) {
                if (temp->next->next == NULL) {
                    temp->next = NULL;
                    return;
                }
                else {
                    temp->next = temp->next->next;
                    temp->next->prev = temp;
                    return;
                }
            }
        }
        cout << "Invalid Position";
    }

    void deleteElement(int element) {
        if (!head) {
            cout << "Linked list empty";
            return;
        }
        if (head->value == element) {
            head = head->next;
            if (head)
                head->prev = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->value != element) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        temp->next->prev = temp;
    }

    Node* reverseDLL(Node* head); // Function prototype

    //to display all the nodes
    void traverse() {
        if (!head) {
            cout << "Linked list empty";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
};

// Definition of reverseDLL function
Node* DLL::reverseDLL(Node* head) {
    if(!head || head->next==NULL) {
            return head;
        }
        Node* back = NULL;

        Node* current = head;
        while(current!=NULL) {
            back = current->prev;
            current->prev = current->next;
            current->next = back;
            current = current->prev;
        }
        return back->prev;
}

int main() {
    DLL dl1;
    dl1.insertAtStart(5);
    dl1.insertAtStart(4);
    dl1.insertAtStart(3);
    dl1.insertAtStart(2);
    dl1.insertAtStart(1);
    dl1.insertAtEnd(6);
    dl1.insertAtPosition(7, 0);
    dl1.insertBeforeElement(6, 10);
    dl1.deleteFromStart();
    // dl1.deleteFromPosition(2);
    //dl1.deleteElement(1);
    //dl1.head = dl1.reverseDLL(dl1.head);

    /* Node* temp = dl1.head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    } */
     dl1.traverse();
    return 0;
}
