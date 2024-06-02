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
    bool isFull() {
        return rear == size-1;
    }
    bool isEmpty() {
        return front==-1;
    }
    void enqueue(int value) {
        if(isFull()) return;

        if(isEmpty()) front++;

        queue[++rear] = value;
    }
    int dequeue() {
        if(isEmpty()) return -1;

        int temp = queue[front];
        if(front==rear) front=rear=-1;
        else {
            front++;
        }
        return temp;
    }
    int peek() {
        if(isEmpty()) return -1;

        return queue[front];
    }

    void traverse() {
        if(isEmpty()) return;

        for(int i=front;i<=rear;i++) {
            cout<<queue[i]<<" ";
        }
    }
};

int main() {
    Queue q1(5);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.dequeue();

    q1.traverse();

    return 0;
}