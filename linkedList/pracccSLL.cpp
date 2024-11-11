#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int data) {
        value = data;
        next  = NULL;
    }
};

class SLL {
    public:
    Node* head;

    SLL() {
        head = NULL;
    }

    SLL findCommon(SLL sl1, SLL sl2) {
        SLL sl3;
        Node* curr1 = sl1.head;
        Node* curr2 = sl2.head;
        Node* prev1 = NULL;
        Node* prev2 = NULL;

        while(curr1 && curr2) {
            if(curr1->value  == curr2->value)  {
                prev1->next = curr1->next;

                prev2->next = curr2->next;       
                Node* temp1 = curr1;
                Node* temp2 = curr2;
                curr1 = curr1->next;
                curr2 = curr2->next;

                temp1->next = sl3.head;
                sl3.head = temp1;

                temp2->next = sl3.head;
                sl3.head = temp2;        

            }
            else if (curr1->value < curr2->value) {
            prev1 = curr1;
            curr1 = curr1->next;
        } else {
            prev2 = curr2;
            curr2 = curr2->next;
        }   
        }
        sl3.head = reverseSLL(sl3.head);
        return sl3;

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
            int currentPosition =1;
            while(currentPosition < position - 1 && temp) {
                temp  = temp->next;
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

    void insertBeforeElement(int elementBefore, int value) {
        Node* n1 = new Node(value);
        if(head->value==elementBefore) {
            n1->next = head;
            head = n1;
        }
        else {
            Node* temp = head;
            while(temp->next!=NULL) {
                if(temp->next->value==elementBefore) {
                    n1->next = temp->next;
                    temp->next = n1;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    
    //deletion operations
    void deleteAtStart() {
        if(!head) {
            return;
        }
        
            Node* temp = head;
            head = head->next;
            delete temp;
        
    }

    void deleteAtEnd() {
        if(!head) {
            return;
        }
        Node* temp = head;
        while(temp->next->next!=NULL) {
            temp = temp->next;
        }
        Node* temp1 = temp->next;
        temp->next = NULL;
        delete temp1;
        
    }

    void deleteFromPosition(int position) {
        if(!head) return;

        if(position==1) {
            Node* temp = head;
            head  = head->next;
            delete temp;
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
            while(currentPosition < position -1 && temp) {
                temp = temp->next;
                currentPosition++;
            }
            if(temp) {
                if(temp->next->next==NULL) {
                    Node* temp1 = temp->next;
                    temp->next = NULL;
                    delete temp1;
                }
                else{
                    Node* temp2 = temp->next;
                    temp->next = temp->next->next;
                    delete temp2;
                }
            }
        }
    }

    void deleteElement(int element) {
        if(!head) return;
        if(head->value==element) {
            Node* temp1 = head;
            head = head->next;
            delete temp1;
        }
        else {
            Node* temp = head;
            while(temp->next->value!=element) {
                temp = temp->next;
            }
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
        }
    }

    void oddEvenLinkedList() {
    if(!head || head->next == NULL) {
        return;
    }
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

Node* sortLL012() {
    Node* temp = head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    while(temp) {
        if(temp->value==0) {
            zero->next = temp;
            zero = temp;
        }
        else if(temp->value ==1) {
            one->next = temp;
            one  = temp;
        }
        else {
            two->next=  temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    
    Node* newHead = zeroHead->next;

    return newHead;

}

    Node* reverseSLL(Node* head) {
        Node* back  =NULL;
        Node* curr = head;
        while(curr) {
            Node* front = curr->next;
            curr->next = back;
            back = curr;
            curr = front;
        }
        return back;
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
        Node* first  = head;
        Node* second = newHead;

        while(second) {
            if(first->value!=second->value) {
                reverseSLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseSLL(newHead);
        return true;
    }

    Node* deletenthNode(Node* head, int n) {
        Node* slow = head;
        Node* fast = head;
        for(int i=0;i<n;i++) {
            fast = fast->next;
        }
        if(fast == NULL) {
            return head->next;
        }
        while(fast->next!=NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        Node* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }

    void traverse() {
        if(!head) return;

        Node* temp = head;
        while(temp) {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
    }

    void removeDuplicates(Node* head) {
        if(!head || head->next ==NULL) {
            return;
        }
        Node* temp = NULL;
        Node* it = NULL;
        Node* current =head;

        while(current) {
            temp  =current;
            it = current->next;

            while(it) {
                if(current->value == it->value) {
                    temp->next = it->next;
                }
                else {
                    temp = it;
                }
                it = it->next;
            }
            current = current->next;
        }
    }

};

Node* reverseSLL(Node* head) {
    if(!head) return head;

    Node* back  = NULL;
    Node* curr = head;
    while(curr) {
        Node* front = curr->next;
        curr->next = back;
        back = curr;
        curr = front;
    }
    return back;
}



int main() {
    //SLL sl1;
    /* sl1.insertAtStart(2);
    sl1.insertAtStart(1);
    sl1.insertAtStart(0);
    sl1.insertAtStart(2);
    sl1.insertAtEnd(0); */
    /* sl1.insertAtPosition(1,0);
    sl1.insertBeforeElement(1,2);
    sl1.deleteAtEnd();
    sl1.deleteFromPosition(6); */
    //sl1.deleteElement(3);
    //sl1.head = reverseSLL(sl1.head);
    //sl1.oddEvenLinkedList();
    //sl1.head = sl1.sortLL012();
    //sl1.insertAtEnd(1);
    //sl1.insertAtEnd(2);
   // sl1.insertAtEnd(3);
   // sl1.insertAtEnd(3);
    //sl1.insertAtEnd(2);
    //sl1.insertAtEnd(0);
    //sl1.deletenthNode(sl1.head, 2);
    //sl1.removeDuplicates(sl1.head);

    /* bool x = sl1.isPalindrome(sl1.head);
    cout<<x; */

    SLL sl1;
    SLL sl2;

    sl1.insertAtEnd(2);
    sl1.insertAtEnd(3);
    sl1.insertAtEnd(4);
    sl1.insertAtEnd(5);
    sl1.insertAtEnd(6);
    sl1.insertAtEnd(7);

    sl2.insertAtEnd(2);
    sl2.insertAtEnd(4);
    sl2.insertAtEnd(6);
    sl2.insertAtEnd(8);

    //sl1.traverse();


    SLL sl3 = sl3.findCommon(sl1,sl2);
    sl3.traverse();






    
    //sl1.traverse();
    return 0;
}
