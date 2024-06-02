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
        if(isFull()) return;

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
        if(isEmpty()) return -1;

        int temp = stack[top];
        top--;
        return temp;
    }
    int peek() {
        if(isEmpty()) return -1;

        return stack[top];
    }
    void traverse() {
        for(int i=top;i>=0;i--) {
            cout<<stack[i]<<endl;
        }
    }
};

int main() {
    Stack s1(5);
    s1.push(2);
    s1.push(4);
    s1.push(6);
    s1.push(8);
    s1.push(10);
    s1.pop();

    s1.traverse();

    return 0;   
}