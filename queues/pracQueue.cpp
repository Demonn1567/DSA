#include <iostream>

using namespace std;

class Queue {
    public:
    int front;
    int rear;
    int size;
    int* queue;

    Queue(int s) {
        size = s;
        front = rear = -1;
        queue = new int[size];
    }
    bool isFull() {
        return rear == size-1;
    }
    bool isEmpty() {
        return front ==-1;
    }
    void enqueue(int value) {
        if(isFull()) {
            return;
        }
        if(isEmpty()) {
            front++;
        }
        queue[++rear] = value;
    }
    int peek() {
        if(isEmpty()) {
            return -1;
        }
        return queue[front];
    }
    int dequeue() {
        if(isEmpty()) {
            return -1;
        }
        int temp =peek();
        if(front==rear) {
            front=rear=-1;
        }
        front++;
        return temp;
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
    q1.dequeue();
    q1.traverse();
    return 0;
}