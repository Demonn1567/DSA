#include <iostream>

using namespace std;

class Stack {
    public:
    int size;
    int top;
    char* stack;

    Stack(int s) {
        size=s;
        top = -1;
        stack = new char[size];
    }
    void push(char value) {
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
    char peek() {
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
    char pop() {
        if(isEmpty()) {
            return -1;
        }
        int temp = peek();
        top--;
        return temp;
    }
};

bool isValidParentheses(string str){
    Stack st(str.length());
    for(int i=0;i<str.length();i++) {
        char ch = str[i];
        if(ch=='('||ch=='{'||ch=='[') {
            st.push(ch);
        }
        else {
            if(!st.isEmpty()) {
                char top = st.peek();
                if((ch==')' && top=='(')||(ch=='}' && top=='{')||(ch==']' && top=='[')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    return st.isEmpty();
}

int main() {
    string str = "({[]})";
    bool x = isValidParentheses(str);
    cout << x;
    return 0;
}
