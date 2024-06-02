#include <iostream>

using namespace std;

class Stack {
    public:
    int size;
    int top;
    int* stack;

    Stack(int s) {
        size = s;
        top = -1;
        stack = new int[size];
    }
    void push(int value) {
        if(isFull()) {
            return;
        }
        top++;
        stack[top] = value;
    }
    bool isFull() {
        return top==size-1;
    }
    bool isEmpty() {
        return top==-1;
    }
    int pop() {
        if(isEmpty()) {
            return -1;
        }
        int temp = peek();
        top--;
        return temp;
    }
    int peek() {
        if(isEmpty()) {
            return -1;
        }
        return stack[top];
    }
    void traverse() {
        if(isEmpty()) {
            return;
        }
        for(int i=top;i>=0;i--) {
            cout<<stack[i]<<endl;
        }
    }
};

int main() {
    Stack s1(5);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    s1.push(9);
    int x = s1.peek();
    cout<<x;
    s1.traverse();

    

    return 0;
}