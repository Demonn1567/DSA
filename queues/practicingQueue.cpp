#include <iostream>

using namespace std;

class Queue {
    public:
    int size;
    int front;
    int rear;
    int* queue;

    Queue(int s) {
        size = s;
        front = rear = -1;
        queue = new int[size];
    }
    void enqueue(int element) {
        if(isFull()) {
            cout<<"Queue is empty";
            return;
        }
        if(isEmpty()) {
            front++;
        }
        queue[++rear] = element;
    }
    bool isFull() {
        return rear==size-1;
    }
    bool isEmpty() {
        return front==-1;
    }
    int dequeue() {
        if(isEmpty()) {
            cout<<"Queue Empty";
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

int main() {
    Queue q1(5);
    q1.enqueue(2);
    q1.enqueue(4);
    q1.enqueue(6);
    q1.enqueue(8);
    q1.enqueue(10);
    int temp = q1.peek();
    cout<<temp<<endl;
    q1.traverse();
    return 0;
}