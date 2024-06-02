#include <iostream>

using namespace std;

class circularQueue {
    public:
    int size;
    int front;
    int rear;
    int* queue;

    circularQueue(int s) {
        size = s;
        front = rear = -1;
        queue = new int[size];
    }
    void enqueue(int element) {
        if(isFull()) {
            return;
        }
        if(isEmpty()) {
            front++;
        }
        rear = (rear+1)%size;
        queue[rear] = element;
    }
    bool isEmpty() {
        return front ==-1;
    }
    bool isFull() {
        return (rear+1)%size==front;
    }
    int dequeue() {
        if(isEmpty()) {
            return -1;
        }
        int temp = peek();
        if(front==rear) {
            front=rear=-1;
        }
        else {
            front = (front+1)%size;
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
        for(int i=front;i!=rear;i=(i+1)%size) {
            cout<<queue[i]<<" ";
        }
        cout<<queue[rear];
    }
};

int main() {
    circularQueue q1(5);
    q1.enqueue(2);
    q1.enqueue(4);
    q1.enqueue(6);
    q1.enqueue(8);
    q1.enqueue(10);
    q1.dequeue();
    q1.enqueue(2);
    q1.traverse();
    return 0;
}