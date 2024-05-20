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
    void insertAtStart(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = n1;
            return;
        }
        n1->next = head;
        head = n1;
    }
    void insertAtEnd(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = n1;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = n1;
    }
    void insertAtPosition(int position, int value) {
        Node* n1 = new Node(value);
        if(position ==1) {
            if(!head) {
                head = n1;
                return;
            }
            else {
                n1->next = head;
                head = n1;
            }
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
            while(currentPosition < position -1&& temp) {
                temp = temp->next;
                currentPosition++;
            } 
            if(temp) {
                if(temp->next==NULL) {
                    temp->next = n1;
                }
                else {
                    n1->next = temp->next;
                    temp->next = n1;
                }
            }
        }
    }

    void insertBeforeElement(int element, int value) {
        Node* n1 = new Node(value);
        if(head->value == element) {
            n1->next = head;
            head = n1;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL) 
        {
            if(temp->next->value == element) {
                n1->next = temp->next;
                temp->next = n1;
                break;
            }
            temp = temp->next;
        }
    }

    void deleteAtStart() {
        if(!head) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteAtEnd() {
        if(!head) return;
        
        Node* temp = head;
        while(temp->next->next!=NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void deleteFromPosition(int position) {
        if(!head) return;
        if(position==1) {
            Node* temp = head;
            head = head->next;
            return;
        }
        else {
            Node* temp = head;
            int currentPosition =1;
            while(currentPosition < position -1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp) {
                if(temp->next->next == NULL) {
                    temp->next  = NULL;
                }
                else {
                    temp->next = temp->next->next;
                }
            }
        }
    }

    void deleteElement(int element) {
        if(!head) return;
        if(head->value == element) {
            head = head->next;
        }
        else {
            Node* temp = head;
            while(temp->next->value !=element) {
                temp = temp->next;
            }   
            if(temp) {
                temp->next = temp->next->next;
            }
            else {
                cout<<"Invalid Element";
            }
        }
    }

    void deleteLinkedList() {
        if(!head) return;
        Node* current = head;
        Node* newNode = NULL;

        while(current!=NULL) {
            newNode = current->next;
            delete current;
            current = newNode;
        }
        head = NULL;
    }

    void swap(Node* p) {
        Node* temp1 = p->next;
        Node* temp2 = p->next->next;

        p->next = temp2;
        temp1->next = temp2->next;
        temp2->next = temp1;
    } 

    void maxElement() {
        int max = head->value;
        Node* temp = head->next;
        while(temp) {
            if(temp->value > max) {
                max = temp->value;
            }
            temp = temp->next;
        }
        cout<<"The max value is"<<max;
    }

    void firstSecondMax() {
        Node* temp = head;
        int max1, max2;
        if(!head) return;

        if(temp->value > temp->next->value) {
            max1 = temp->value;
            max2 = temp->next->value;
        }
        else {
            max1 = temp->next->value;
            max2 = temp->value;
        }

        Node* ptr  = temp->next->next;
        while(ptr) {
            if(ptr->value > max1) {
                int temp1 = max1;
                max1 = ptr->value;
                max2 = temp1;
            }
            else if(ptr->value > max2) {
                max2 = ptr->value;
            }
            ptr = ptr->next;
        }
        cout<<"The first and second max elements are "<<max1<<" & "<<max2;

    }

    




    void traverse() 
    {
        if(!head) {
            cout<<"Linked List Empty";
            return;
        }
        Node* temp = head;
        while(temp) {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
    }
    

    Node* reverseSLLRecursively(Node* head) {
        if(!head || head->next == NULL) return head;

        Node* newHead = reverseSLLRecursively(head->next);

        Node* front = head->next;
        front->next = head;
        head->next  = NULL;

        return newHead;
         
    }

    bool detectCycle(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast) return true;
        }
        return false;
    }

    
    
    



    
};
Node* reverseSLL(Node* head) {
        Node* temp = head;
        Node* prev  = NULL;

        while(temp) {
            Node* front = temp->next;
            temp->next = prev;

            prev = temp;
            temp = front;
        }
        return prev;
    }

    //group the odd indexed nodes first and the even indexed nodes after
    void oddEvenList(Node* head) {
        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = head->next;
        while(even!=NULL && even->next!=NULL) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;

    }

Node* sortLLof012(Node* head) {
        if(!head || head->next==NULL) return head;
        Node* zeroHead = new Node(-1); Node* zero = zeroHead;
        Node* oneHead = new Node(-1);   Node* one = oneHead;
        Node* twoHead = new Node(-1);   Node* two = twoHead;

        Node* temp = head;
        while(temp) {
            if(temp->value == 0) {
                zero->next = temp;
                zero = temp;
            }
            else if(temp->value == 1) {
                one->next = temp;
                one = temp;
            }
            else {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;

        return zeroHead->next; 
    }


bool isPalindrome(Node* head) {
        if(!head || head->next==NULL) return true;

        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newHead = reverseSLL(slow->next);

        Node* first = head;
        Node* second = newHead;

        while(second!=NULL) {
            if(first->value !=second->value) {
                reverseSLL(newHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }
        reverseSLL(newHead);
        return true;

    }

Node* deleteAllOccurences(Node* head, int key) {
    if(!head) return head;
    if(head->value==key) head = head->next;

    Node* temp = head;
    while(temp && temp->next) {
        if(temp->next->value == key) temp->next = temp->next->next;

        temp = temp->next;
    }
    return head;

    /* if(!head) return head;
    
    Node* temp = head;
    if(head->value == key) {
        head = head->next;
        delete temp;
    }
    Node* temp2 = head;
    while(temp2 && temp2->next) {
        if(temp2->next->value == key) {
            Node* deleteNode = temp2->next;
            temp2->next = temp2->next->next;
            delete deleteNode;
        }
        else {
            temp2 = temp2->next;
        }
    }
    return head; */

}

Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast!=NULL  && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

int main() {
    SLL sl1;
    sl1.insertAtStart(0);
    sl1.insertAtEnd(2);
    sl1.insertAtEnd(0);
    sl1.insertAtEnd(1);
    sl1.insertAtEnd(2);
    sl1.insertAtEnd(0);
    sl1.insertAtEnd(1);
    //sl1.firstSecondMax();
        //sl1.swap(sl1.head);
    //sl1.deleteLinkedList();

    //Node* middleNode = findMiddle(sl1.head);

    //cout<<"THe middle node is"<<middleNode->value;

    /* int x = isPalindrome(sl1.head);
    cout<<x; */

     
    //oddEvenList(sl1.head);

    //sortLLof012(sl1.head); 
    deleteAllOccurences(sl1.head, 2);

    Node* temp = sl1.head;
    while(temp) {
        cout<<temp->value<<" ";
        temp = temp->next;
    } 



    //sl1.traverse();
}