#include <iostream>
using namespace std;

class node {

public:
    int data;
    node* next;

    node(int value, node* ptr) {
        data = value;
        next = ptr;
    }
};


class queue {

public:
    node* front;
    node* rear;

    queue() {
        front = rear = nullptr;
    }

    void enqueue(int value) {
        node* nn = new node(value, nullptr);
        if (rear == nullptr) {
            rear = nn;
            front = rear = nn;
            return;
        }
        rear -> next = nn;
        rear = nn;
    }

    int dequeue() {
        node* front_node = front;
        int data = front -> data;
        front = front -> next;
        return data;
    }

    void print() {
        node* temp = front;
        while(temp != nullptr)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
        cout << "front at : " << front -> data << endl;
        cout << "rear at  : " << rear -> data << endl;
    }
};

int main() {
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
    q.enqueue(40);
    q.enqueue(50);
    q.print();
    q.dequeue();
    return 0;
}