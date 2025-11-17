// implementation of stack using array

#include <iostream>
using namespace std;


class Stack
{
public:
    int top;
    int size;
    int *arr;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int x)
    {
        // allow push when top is less than last index (size-1)
        if (top < size - 1)
            arr[++top] = x;
        else
            cout << "stack is overflow\n";
    }

    void pop()
    {
        if (top >= 0)
        {
            arr[top--] = -1;
        }
        else
            cout << "stack is underflow\n";
    }

    bool empty()
    {
        return top == -1;
    }

    int peek()
    {
        if (!empty())
            return arr[top];
        else
            return -1;
    }

    int getSize()
    {
        // return number of elements currently in the stack
        return top + 1;
    }

    void printStack()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i];
            if (i != top) cout << ", ";
        }
        cout << '\n';
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack st(5);
    st.push(5);
    st.push(10);
    st.push(12);
    st.push(15);
    st.push(20);
    st.printStack();
    cout << "top element: " << st.peek();
}