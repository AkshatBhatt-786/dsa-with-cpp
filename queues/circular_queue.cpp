#include <iostream>
using namespace std;

class CircularQueue {
    
    int* arr;
    int size;
    int qfront;
    int rear;

public:
    CircularQueue() {
        size = 5;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    bool enqueue(int value) {
        if ((rear == (qfront-1)%(size-1)) || (qfront == 0 && rear == size - 1)) {
            cout << "Queue is full!";
            return false;
        } else if (qfront == -1) {
            rear = qfront = 0;
        } else if (rear == size - 1 && qfront != 0) { // to maintain cyclic nature
            rear = 0;
        } else {
            // normal flow
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    int dequeue() {
        if (qfront == -1) { // to check queue is empty
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int ans = arr[qfront];
        arr[qfront] = -1;
        if (qfront == rear) {
            qfront = rear = -1;
        }
        else if (qfront == size - 1) {
            qfront = 0; // to maintain cyclic nature
        }
        else {
            // normal flow
            qfront ++;
        }
        return ans;

    }

    int front() {
    	if (qfront == -1) {
    		cout << "Queue is empty" << endl;
    		return -1;
    	}
    	return arr[qfront];
    }
};

int main() {
	CircularQueue q;
	q.enqueue(5);
	cout << "Front at: " << q.front() << endl;
	q.enqueue(6);
	cout << "Front at: " << q.front() << endl;
	q.enqueue(7);
	cout << "Front at: " << q.front() << endl;
	q.enqueue(8);
	cout << "Front at: " << q.front() << endl;
	cout << "Dequeue operation : " << q.dequeue() << endl;
	cout << "Front at: " << q.front() << endl;
	cout << "Dequeue operation : " << q.dequeue() << endl;
	cout << "Front at: " << q.front() << endl;
}