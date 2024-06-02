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
        queue = new int [size];
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
    bool isFull() {
        return rear==size-1;
    }
    bool isEmpty() {
        return front==-1;
    }
    int dequeue() {
        if(isEmpty()) {
            return -1;
        }
        int temp =peek();
        if(front==rear) {
            front = rear=-1;
        }
        front++;

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
    q1.enqueue(5);
    q1.enqueue(63);
    q1.enqueue(3);
    q1.enqueue(1);
    q1.enqueue(23);
    q1.dequeue();

    q1.traverse();

    return 0;
}