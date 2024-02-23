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

    void Enqueue(int value) {
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
            cout<<"queue is empty";
            return -1;
        }
        return queue[front];
    }

    int dequeue() {
        if(isEmpty()) {
            cout<<"The queue is empty";
            return -1;
        }
        else {
            int temp = peek();
            if(front == rear) {
                front = rear = -1;
            }
            else {
                front++;
            }
            return temp;
        }

    }

    void traverse() {
        if(isEmpty()) {
            cout<<"The queue is empty";
            return;
        }
        for(int i=front;i<=rear;i++) {
            cout<<queue[i]<<" ";
        }

    }

};

int main() {
    Queue q1(5);
    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);
    q1.Enqueue(40);
    q1.Enqueue(50);
    q1.dequeue();
    q1.traverse();

    return 0;
}