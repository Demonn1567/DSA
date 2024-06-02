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

    void enqueue(int value) {
        if(isFull()) {
            return;
        }
        if(isEmpty()) {
            front++;
        }
        rear = (rear+1)%size;
        queue[rear] = value;
    }
    bool isFull() {
        return (rear+1)%size==front;
    }
    bool isEmpty() {
        return front==-1;
    }
    int dequeue() {
        if(isEmpty()) {
            return -1;
        }
        int temp = peek();

        if(front==rear) {
            front=rear=-1;
        }
        front = (front+1)%size;

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
        for(int i=front;i!=rear;i=(i+1)%size) {
            cout<<queue[i]<<" ";
        }
        cout<<queue[rear];
    }
};

int main() {
    Queue q1(5);
    q1.enqueue(5);
    q1.enqueue(11);
    q1.enqueue(3);
    q1.enqueue(7);
    q1.enqueue(1);
    q1.dequeue();
    q1.enqueue(5);

    q1.traverse();

    return 0;
}