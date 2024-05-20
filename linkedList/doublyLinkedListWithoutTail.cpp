#include <iostream>
#include <vector>
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

void convertArrtoDLL(vector<int> arr) {
        Node* head = new Node(arr[0]);
        Node* back = head;
        for(int i=0;i<arr.size();i++) {
            Node* temp = new Node(arr[i]);
            back->next = temp;
            temp->prev = back;
            back = temp;
        }
    }

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
        }
        else {
            n1->next = head;
            head->prev = n1;
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
            n1->prev = temp;
        }
    }

    void insertAtPosition(int position, int value) {
        Node* n1 = new Node(value);
        if(position == 1) {
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
        Node* ptr = NULL;
        int count = 0;
        while(temp!=NULL) {
            count++;
            if(count == position) break;
            ptr = temp;
            temp = temp->next;
        }
        
        if(ptr->next==NULL) {
            ptr->next = n1;
            n1->prev = ptr;
        }
        else {
            
            n1->next = ptr->next;
            n1->next->prev = n1;
            ptr->next = n1;
            n1->prev = ptr;
        }
        
      }
    }

    void insertBeforeElement(int elementBefore, int value) {
        Node* n1 = new Node(value);
        if(head->value == elementBefore) {
            n1->next = head;
            head->prev = n1;
            head = n1;
            return;
        }
        else {
            Node* temp = head;
            while(temp->next!=NULL) {
                if(temp->next->value == elementBefore) {
                    n1->next = temp->next;
                    temp->next->prev = n1;
                    temp->next = n1;
                    n1->prev = temp;
                    return;
                }
                temp = temp->next;
            }
            cout<<"Invalid element entered";
        }

    }

    void deleteFromStart() {
        if(!head) {
            cout<<"Empty Linked List";
            return;
        }
        head = head->next;
        head->prev = NULL;   
    }
    void deleteFromEnd() {
        if(!head) {
            cout<<"Empty Linked List";
            return;
        }
        Node* temp = head;
        while(temp->next->next !=NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void deleteFromPosition(int position) {
        if(!head) {
            cout<<"Empty Linked List";
            return;
        }
        if(position == 1) {
            head = head->next;
            head->prev = NULL;
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
            while(currentPosition < position-1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp) 
            {
                if(temp->next->next == NULL) {
                    temp->next = NULL;
                }
                else {
                    temp->next = temp->next->next; 

                    temp->next->prev = temp;
                }
            }
        }
    }

    void deleteFromPosition2(int position) {
        int count = 0;
        Node* temp = head;
        while(temp!=NULL) {
            count++;
            if(count == position) break;
            temp = temp->next;
        }
        Node* back = temp->prev;
        Node* front = temp->next;

        if(back == NULL && front == NULL) {
            cout<<"Empty Linked List";
            return;
        }
        if(back == NULL) {
            head = head->next;
            head->prev = NULL;
            return;
        }
        if(front == NULL) {
            deleteFromEnd();
            return;
        }
        back->next = front;
        front->prev = back;

        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    void deleteNode(int element) {
        if(!head) {
            cout<<"Linked list empty";
            return;
        }
        if(head->value==element) {
            head = head->next;
            head->prev = NULL;
        }
        else 
        {
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
            cout<<"Empty Linked List";
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
        if(!head || head->next==NULL) return head;

        Node* back  = NULL;
        Node* curr = head;

        while(curr!=NULL) {
            back = curr->prev;
            curr->prev = curr->next;
            curr->next = back;
            curr = curr->prev;
        }

        return back->prev;
        
    }


int main() {
    DLL dl1;

    
    
    dl1.insertAtStart(10);
    dl1.insertAtStart(8);
    dl1.insertAtStart(6);
    dl1.insertAtStart(4);
    dl1.insertAtStart(2);
    dl1.insertAtEnd(12);
    dl1.insertBeforeElement(12, 11);
    dl1.deleteNode(12);

    dl1.head = reverseDLL(dl1.head);
    Node* temp = dl1.head;
    while(temp) {
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    
    //dl1.traverse();
}