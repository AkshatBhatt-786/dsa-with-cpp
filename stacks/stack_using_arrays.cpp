#include <iostream>
using namespace std;

class Stack {
    int capacity;
    int top;
    int* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    void push(int value) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == capacity - 1;
    }

    int get_size() {
        return top + 1;
    }

    void display() {
        if (is_empty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack st(5);
    st.push(20);
    st.push(10);
    st.push(50);
    st.push(70);

    cout << "Top element: " << st.peek() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.display();

    cout << "Is Empty? " << (st.is_empty() ? "Yes" : "No") << endl;
    cout << "Is Full? " << (st.is_full() ? "Yes" : "No") << endl;
    cout << "Current Size: " << st.get_size() << endl;

    return 0;
}
