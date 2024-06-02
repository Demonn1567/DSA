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

void sortedInsert(Stack& s, int num) {
    if(s.isEmpty()||(!s.isEmpty()&&s.peek()<num)) {
        s.push(num);
        return;
    }
    int n = s.peek();
    s.pop();

    sortedInsert(s,num);

    s.push(n);
}

void sortStack(Stack& s) {
    if(s.isEmpty()) return;

    int num = s.peek();
    s.pop();
    sortStack(s);

    sortedInsert(s, num);
}


int main() {
    Stack s1(5);
    s1.push(23);
    s1.push(13);
    s1.push(46);
    s1.push(34);
    s1.push(11);
    cout<<"The original stack is : ";
    s1.traverse();
    sortStack(s1);
    cout<<endl<<"The sorted stack is : ";
    s1.traverse();

    return 0;
}
