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

class SLL{
    public:
    Node* head;

    SLL() {
        head = NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void traverse() {
        if(!head) {
            cout<<"Linked list empty";
            return;
        }
        Node* temp = head;
        while(temp!=NULL) {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
    }

};

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

        while (current != end && current->next != NULL) {
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





Node* mergeTwoLists(Node* list1, Node* list2) {
        if(!list1) {
            return list2;
        }
        if(!list2) {
            return list1;
        }

        if(list1->value < list2->value) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }
        
    }



int main() {
    SLL sl1, sl2;

    sl1.insert(4);
    sl1.insert(17);
    sl1.insert(2);
    sl1.insert(8);
    cout<<"List 1 is :";
    sl1.traverse();

    cout<<endl;
    
    sl2.insert(9);
    sl2.insert(11);
    sl2.insert(3);
    sl2.insert(1);
    cout<<"List 2 is :";
    sl2.traverse();

    cout<<endl;

    Node* mergedListHead1 = mergeTwoLists(sl1.head, sl2.head);
    Node* mergedSortedList = bubbleSort(mergedListHead1);

    cout << "Merged list is :";
    Node* temp = mergedSortedList;
    while (temp != NULL) {
    cout << temp->value << " ";
    temp = temp->next;
}


 
}