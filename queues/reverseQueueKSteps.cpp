#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Queue {
    public:
    int size;
    int front;
    int rear;
    int* queue;

    Queue(int s) {
        size=s;
        front=rear=-1;
        queue = new int[size];
    }
    void enqueue(int element) {
        if(isFull()) {
            return;
        } 
        if(isEmpty()) {
            front++;
        }
        queue[++rear] = element;
    }
    bool isEmpty() {
        return front==-1;
    }
    bool isFull() {
        return rear ==size-1;
    }
    int dequeue() {
        if(isEmpty()) 
        {
            return -1;
        }
        int temp = peek();
        if(front==rear) {
            front=rear=-1;
        }
        else {
        front++;
        }

        return temp;
    }
    int peek() {
        if(isEmpty()) {
            return -1;
        }
        return queue[front];
    }
    void traverse() {
        if(isEmpty()) {
            return;
        }
        for(int i=front;i<=rear;i++) {
            cout<<queue[i]<<" ";
        }
    }
    
    
};

void reverseQueueKSteps(queue<int>& q , int k) {
    stack<int> s;
    for(int i=0;i<k;i++) {
        int num  = q.front();
        q.pop();
        s.push(num);
    }
    while(!s.empty()) {
        int n = s.top();
        s.pop();
        q.push(n);
    }
    int t = q.size() - k;
    while(t--) {
        int v = q.front();
        q.pop();
        q.push(v);
    }
}

int main() {
    queue<int> q1;
    q1.push(2);
    q1.push(4);
    q1.push(6);
    q1.push(8);
    q1.push(10);
    

    cout<<endl<<"The reversed array by k steps is : ";
    reverseQueueKSteps(q1,3);
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    }

    return 0;
}

