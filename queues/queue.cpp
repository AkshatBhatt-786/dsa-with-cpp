#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int size;
    int qfront;
    int rear;

public:
    Queue(int capacity) {
        size = capacity;
        arr = new int[size];
        qfront = rear = 0;
    }

    void enqueue(int value) {
        if (rear == size) {
            cout << "Queue is full!" << endl;
        } else {
            arr[rear] = value;
            rear++;
        }
    }

    int dequeue() {
        if (qfront == size) {
            cout << "Queue is Empty!" << endl;
        } else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront ++;
            if (qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (qfront == rear) {
            return -1;
        }
        return arr[qfront];
    }

    bool isEmpty() {
        if (qfront == rear) return true;
        return false;
    }

    bool isFull() {
        if (rear == size) return true;
        return false;
    }
};

int main() {
    Queue q(5);
    q.enqueue(5);
    q.enqueue(6);
    cout << "front at position: " << q.front() << endl;
    cout << "deleteing element from queue: " << q.dequeue();
    return 0;
}