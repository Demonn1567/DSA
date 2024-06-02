#include <iostream>
#include <stack>

using namespace std;

class Stack {
    public:
    int size;
    int top;
    int* stack;

    Stack(int s) {
        size = s;
        top =-1;
        stack = new int [size];
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

    //deleting middle element from the stack
    void deleteMiddleElement(Stack& s, int count , int size) {
        if(count==size/2) {
            s.pop();
            return;
        } 
        int num = s.peek();
        s.pop();
        deleteMiddleElement(s, count+1, size);
        s.push(num);
    }

    //inserting an element at the bottom of the stack
    void insertBottom(Stack& s, int element) {
        if(s.isEmpty()) {
            s.push(element);
            return;
        }
        int num = s.peek();
        s.pop();
        insertBottom(s,element);
        s.push(num);
    }

    //reversing a stack using recursion
    void reverseStack(Stack& s) {
        if(s.isEmpty()) {
            return;
        }
        int num = s.peek();
        s.pop();
        reverseStack(s);
        insertBottom(s,num);
    }

    //sort a stack
    void sortedInsert(Stack& s, int num) {
        if(s.isEmpty() || (!s.isEmpty()&&s.peek()<num)) {
            s.push(num);
            return;
    }
    int n = s.peek();
    s.pop();
    sortedInsert(s, num);
    s.push(n);

    }
    void sortStack(Stack& s) {
        if(s.isEmpty()) {
            return;
        }
        int num = s.peek();
        s.pop();
        sortStack(s);
        sortedInsert(s,num);
    }
};

int main() {
    Stack s1(6);
    s1.push(5);
    s1.push(6);
    s1.push(3);
    s1.push(1);
    s1.push(10);
    //s1.deleteMiddleElement(s1,0,5);
    //s1.reverseStack(s1);
    s1.sortStack(s1);

    s1.traverse(); 
    //reversing a string using a stack
    /* string str = "krish sharma";
    stack<char> s;
    for(int i=0;i<str.length();i++) {
        char ch  = str[i];
        s.push(ch);
    }

    string result = "";
    while(!s.empty()) {
        char ch = s.top();
        result.push_back(ch);
        s.pop();
    }

    cout<<result; */




    return 0;
}