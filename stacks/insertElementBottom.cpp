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
        for(int i=0;i<=top;i++) {
            cout<<stack[i]<<" ";
        }
    }
};

void insertAtBottom(Stack& s, int element) {
    if(s.isEmpty()) {
        s.push(element);
        return;
    }
    int num = s.peek();
    s.pop();
    insertAtBottom(s, element);
    s.push(num);
}

int main() {
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    insertAtBottom(s1,50);

    s1.traverse();
    

    return 0;
}