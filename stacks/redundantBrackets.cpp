#include <iostream>
#include <stack>

using namespace std;

class Stack {
  public:
  int size;
  int* stack;
  int top;

  Stack(int s) {
    size=s;
    top=-1;
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

bool findRedundantBrackets(string &s) {
  stack<char> st;
  for(int i=0;i<s.length();i++) {
    char ch = s[i];

    if(ch=='('||ch=='*'||ch=='+'||ch=='-'||ch=='/') {
      st.push(ch);
    }
    else { //either ')' or lowercase character
    if(ch==')') {
      bool isRedundant = true;
      while(st.top()!='(') {
        char top = st.top();
        if(top=='*'||top=='+'||top=='-'||top=='/') {
          isRedundant = false;
        }
        st.pop();
      }
      if(isRedundant == true) {
        return true;
      }
      st.pop();
    }
  }

  }
  return false;
}


int main() {
  string s = "(a+b)";
  bool x = findRedundantBrackets(s);
  cout<<x;
  
  return 0;
}