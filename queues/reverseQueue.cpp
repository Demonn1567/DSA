#include <iostream>
#include <stack>


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

void reverseQueue(Queue& q) {
    stack<int> st;
    while(!q.isEmpty()) {
        st.push(q.dequeue());
    }
    while(!st.empty()) {
        q.enqueue(st.top());
        st.pop();
    }
}



int main() {
    Queue q1(5);
    q1.enqueue(2);
    q1.enqueue(4);
    q1.enqueue(6);
    q1.enqueue(8);
    q1.enqueue(10);
    cout<<"The original queue is :";
    q1.traverse();

    cout<<endl<<"The reversed queue is : ";
    reverseQueue(q1);
    q1.traverse();


    return 0;
}
