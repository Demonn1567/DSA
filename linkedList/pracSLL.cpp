#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;

    Node(int data) {
        value =data;
        next = NULL;
    }
};

class SLL {
    public:
    Node* head;

    SLL() {
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
            head = n1;
        }
    }

    void insertAtEnd(int value) {
        Node* n1 = new Node(value);
        if(!head) {
            head = n1;
        }
        else{
            Node* temp = head;
            while(temp->next!=NULL) {
                temp = temp->next;
            }
            temp->next = n1;
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
                head = n1;
            }
        }
        else {
            Node* temp = head;
            int currentPosition=1;
            while(currentPosition<position-1 && temp) {
                temp=temp->next;
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
            cout<<"Linked list empty";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if(!head) {
            cout<<"Linked list empty";
            return;
        }
        Node* temp = head;
        while(temp->next->next!=NULL) {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void deleteFromPosition(int position) {
        if(!head) {
            cout<<"Linked list empty";
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
                if(temp->next->next==NULL) {
                    temp->next=NULL;
                }
                else {
                temp->next = temp->next->next;
                }
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
        if(head->value==element) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node* temp = head ;
            while(temp->next->value!=element) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    }

    void deleteLinkedList() {
        Node* current = head;
        Node* newnode;

        while(current!=NULL) {
            newnode = current->next;
            delete current;
            current = newnode;
        }
        head = NULL;
    }


    //traversing the linked list
    void displayNodes() {
        if(!head) {
            cout<<"Linked list empty";
            return;
        }
        Node* temp = head;
        while(temp!=NULL) {
            cout<<temp->value<<" ";
            temp=temp->next;
        }
    }

    //bubble sorting in the singly linked list

    Node* swap(Node* ptr1, Node* ptr2) {
        Node* temp = ptr2->next;
        ptr2->next = ptr1;
        ptr1->next = temp;

        return ptr2;
    }

    Node* bubbleSort(Node* head) {
    if (!head || head->next == NULL) {
        return head;
    } 
    Node* end = NULL;
    bool swapped;

    do {
        swapped = false;
        Node* current = head;
        Node* prev = NULL; 

        while (current != end && current->next != prev) {
            if (current->value > current->next->value) {
                if (prev) {
                    prev->next = swap(current, current->next);
                } else {
                    head = swap(current, current->next);
                }
                swapped = true;
            }
            prev = current;
            current = current->next;
        }
        
    } while (swapped);

    return head;
}

void maxElement() {
    int max1 = head->value;
    Node* temp = head->next;
    while(temp!=NULL) {
        if(temp->value > max1) {
            max1 = temp->value;
        }
        temp = temp->next;
    }
    cout<<"The maximum element in the linked list is : "<<max1;
}

void swap(Node* p) {
    Node* temp1 = p->next;
    Node* temp2 = p->next->next;
    Node* temp3 = temp2->next;
    temp2->next = temp1;
    p->next = temp2;
    temp1->next = temp3;
}

void firstSecondMaxElement() {
    Node* temp = head;
    int max1,max2;
    if(temp==NULL) {
        return;
    }
    if(temp->next == NULL) {
        max1 = temp->value;
        cout<<max1;
        return;
    }
    if(temp->value > temp->next->value) {
         max1 = temp->value;
         max2 = temp->next->value;
    }
    else {
         max1 = temp->next->value;
         max2 = temp->value;
    }
    Node* ptr = temp->next->next;
    while(ptr!=NULL) {
        if(ptr->value>max1) {
            int temp = max1;
            max1 = ptr->value;
            max2 = temp;
        }
        else if(ptr->value >max2) {
            max2 = ptr->value;
        }
        ptr = ptr->next;
    }
    cout<<"The two maximum elements in the linked list are : "<<max1<<"&"<<max2;
}

    Node* addTwoNumbers(Node* head1, Node* head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;
        Node* dummyNode = new Node(-1);
        Node* curr = dummyNode;
        int carry=0,sum=0;
        while(temp1!=NULL || temp2!=NULL) {
            sum = carry;
            if(temp1) sum+=temp1->value;
            if(temp2) sum+=temp2->value;

            Node* newNode = new Node(sum%10);
            carry = sum/10;

            curr->next = newNode;
            curr = curr->next;

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;

            
        }
        if(carry) {
            Node* newNode = new Node(carry);
            curr->next = newNode;
        }
        return dummyNode->next;

    }

    void displayEvenNodes() {
        if(!head) {
            cout<<"Linked list empty";
            return;
        }
        Node* temp = head;
        while(temp!=NULL) {
            if(temp->value%2==0) {
                cout<<temp->value<<" ";
            }
            temp = temp->next;
        }
    }
    void oddEvenLinkedList() {
        int arr[10];
        Node* temp = head;int i=0;
        while(temp!=NULL && temp->next!=NULL) {
            arr[i]  = temp->value;
            i++;
            temp = temp->next->next;
        }
        if(temp) {
            arr[i] = temp->value;
            i++;
        }
        Node* temp1 = head->next;
        while(temp1!=NULL && temp1->next!=NULL) {
            arr[i]  = temp1->value;
            i++;
            temp1 = temp1->next->next;
        }
        if(temp1) {
            arr[i] = temp1->value;
            i++;
        }
        int j=0;
        Node* temp2 = head;
        while(temp2!=NULL) {
            temp2->value = arr[j];
            j++;
            temp2 = temp2->next;
        }
        
    }

    void oddEvenLinkedList2() {
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

    Node* sortLinkedList012(Node* node) {
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
            else if(temp->value==1) {
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

        Node* newHead = zeroHead->next;

        return newHead;
    }

    Node* swapp(Node* p) {
        Node* prev = p;
        Node* curr = prev->next;
        Node* next = curr->next;

        prev->next = next;
        curr->next = next->next;
        next->next = curr;

        return p;
    }

    Node* middleLinkedList(Node* head) {
       // if(!head) return head;

        Node* slow = head;
        Node* fast = head;

        while(fast!=NULL || fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    

    
};

int main() {
    SLL sl1;
    sl1.insertAtEnd(2);
    sl1.insertAtEnd(0);
    sl1.insertAtEnd(2);
    sl1.insertAtEnd(1);
    sl1.insertAtEnd(0);
    sl1.insertAtEnd(1);
    //sl1.displayNodes();

    //sl1.oddEvenLinkedList2();
    /* sl1.head = sl1.swapp(sl1.head);
    Node* temp = sl1.head;
    while(temp!=NULL) {
        cout<<temp->value<<" ";
        temp = temp->next;
    } */
    Node* mid;
    mid = sl1.middleLinkedList(sl1.head);

    cout<<mid;

    //sl1.displayNodes();


    
    //sl1.insertAtPosition(5,1);
    //sl1.head = sl1.bubbleSort(sl1.head);
    //sl1.deleteFromPosition(4);
    //sl1.swap(sl1.head);
    //sl1.displayNodes();
    //cout<<endl;
    //sl1.maxElement();
    //sl1.deleteAtStart();
    //sl1.deleteAtEnd();
    //sl1.deleteFromPosition(0);
    //sl1.deleteElement(-1);
    //sl1.deleteLinkedList();

    //sl1.displayEvenNodes();
    return 0;
}