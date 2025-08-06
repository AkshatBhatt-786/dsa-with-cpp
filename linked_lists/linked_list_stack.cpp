#include <iostream>
using namespace std;

class node {

public:
    int data;
    node* next;

    node(int value, node* top) {
        data = value;
        next = top;
    }
};

class stack {

public:
    node* top;

    stack() {
        top = nullptr;
    }

    int push(int dateum) {
        node* nn = new node(dateum, top);
        top = nn;
        return 1;
    }

    int peek() {return top -> data;}

    int pop() {
        int data = top -> data;
        top = top -> next;
        return data;
    }

    
    void print() {
        node* temp = top;
        if (temp == nullptr) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        while(temp != nullptr)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
        cout << "peek element :" << peek() << endl;
    }
};

int main() {
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.print();
    st.pop();
    st.push(40);
    st.print();
}