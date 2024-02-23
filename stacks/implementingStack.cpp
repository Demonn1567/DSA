#include <iostream>

using namespace std;

class Stack {
    public:
    int* stack;
    int size;
    int top;

    Stack(int s) {
        size = s;
        top = -1;
        stack = new int[size];
    }

    void push(int val) {
        if(isFull()) {
            cout<<"The stack is empty";
            return;
        }
        top++;
        stack[top] = val;
    }
    bool isFull() {
        return top == size-1;
    }
    bool isEmpty() {
        return top ==-1;
    }
    int pop() {
        if(isEmpty()) {
            cout<<"The stack is empty";
            return -1;
        }
        int temp = peek();
        top--;
        return temp;
        
    }
    int peek() {
        if(isEmpty()) {
            cout<<"The stack is empty";
            return -1;
        }
        cout<<stack[top];

        return 0;

    }

    void traverse() {
        for(int i=0;i<=top;i++) {
            cout<<stack[i]<<" ";
        }
    }

};

int main() {
    Stack s1(5);
    int element, option;

    do {
        cout<<"1:Push an element"<<endl;
        cout<<"2:Delete the topmost element"<<endl;
        cout<<"3:Peek the topmost element"<<endl;
        cout<<"4:Traverse the whole stack"<<endl;
        cout<<"5:Exit"<<endl;

        cout<<"Enter an option :"<<endl;
        cin>>option;
        switch(option) {
            case 1:
                cout<<"Enter the element to be pushed :";
                cin>>element;
                s1.push(element);
                break;

            case 2:
                s1.pop();
                cout<<"Topmost element deleted";
                break;

            case 3:
                s1.peek();
                break;

            case 4:
                s1.traverse();
                break;

            default :
                break;
   
        }
        
    }
    while(option!=5);

    

    return 0;
}