#include <iostream>
#include<stack>

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
            cout<<stack[i]<<" ";
        }
    }
};

void middleElementDelete(Stack&s, int count, int size) {
    if(count == size/2) {
        s.pop();
        return;
    }

    int num = s.peek();
    s.pop();
    middleElementDelete(s, count+1, size);
    s.push(num);
}

int main() {
    Stack s1(5);
    s1.push(5);
    s1.push(7);
    s1.push(9);
    s1.push(11);
    s1.push(13);
    middleElementDelete(s1,0,5);
    s1.traverse();
    return 0;
}