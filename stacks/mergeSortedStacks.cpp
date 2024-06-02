#include <iostream>
#include <stack>

using namespace std;

stack <int> mergeStacks(stack<int> A, stack<int> B) {
    stack <int> result;
    if(A.empty()) {
        return B;
    }
    if(B.empty()) {
        return A;
    }
    int minElement = min(A.top(), B.top());
    if (A.top() == minElement) {
        result.push(A.top());
        A.pop();
    } else {
        result.push(B.top());
        B.pop();
    }

    while(!A.empty() && !B.empty()) {
        int a = A.top();
        int b = B.top();

        

        if(a<=b) {
            result.push(a);
            A.pop();
        }
        else {
            result.push(b);
            B.pop();
        }
    }
    while(!A.empty()) {
        result.push(A.top());
        A.pop();
    }
    while(!B.empty()) {
        result.push(B.top());
        B.pop();
    }

    return result;

}

int main() {
    stack<int> A,B;
    A.push(3);
    A.push(1);
    A.push(5);
    B.push(3);
    B.push(1);
    B.push(5);

    stack<int> result = mergeStacks(A,B);
    while(!result.empty()) {
        cout<<result.top()<<" ";
        result.pop();
    }
    return 0;
}