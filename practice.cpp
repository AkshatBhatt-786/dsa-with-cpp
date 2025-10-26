#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node* prev;
        node* next;
    
    node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyStack
{
public:
    node* first;

    DoublyStack() {
        first = nullptr;
    }

    void push(int val) {
        node* nn = new node(val);
        if (first == nullptr) {
            first = nn;
            return;
        }
        node* temp = first;
        nn -> next = temp;
        first = nn;
    }

    void pop() {
        if (first == nullptr) {
            cout << "nothing to pop....";
            return;
        }
        node* temp = first;
        first = temp -> next;
        delete(temp);
    }

    int top() {
        return first->data;
    }
};

int main()
{
    DoublyStack ds;
    ds.push(10);
    cout << "top : " << ds.top();
    cout << endl;
    ds.push(24);
    cout << "top : " << ds.top();
    cout << endl;
    ds.push(25);
    cout << "top : " << ds.top();
    cout << endl;
    ds.push(50);
    cout << "top : " << ds.top();
    cout << endl;
    ds.pop();
    cout << "top : " << ds.top();
    cout << endl;
    ds.pop();
    cout << "top : " << ds.top();
    cout << endl;

}