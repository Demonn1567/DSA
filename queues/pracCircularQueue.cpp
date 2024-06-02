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
    bool isEmpty() {
        return front==-1;
    }
    bool isFull() {
        return (rear+1)%size==front;
    }
    void enqueue(int value) {
        if(isFull()) return;

        if(isEmpty()) front++;

        rear = (rear+1)%size;
        queue[rear] = value;
    }
    int dequeue() {
        if(isEmpty()) return -1;
        if(front==rear) {
            front = rear = -1;
        }
        else {
            int temp = queue[front];
            front = (front+1)%size;
            return temp;
        }
        return -1;
    }
    int peek() {
        if(isEmpty()) return -1;

        return queue[front];
    }

    void traverse() {
        if(isEmpty()) return;

        for(int i=front;i!=rear;i=(i+1)%size) {
            cout<<queue[i]<<" ";
        }
        cout<<queue[rear];
    }
};

int main() {
    Queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.dequeue();
    q1.enqueue(6);
    q1.traverse();
    return 0;
}