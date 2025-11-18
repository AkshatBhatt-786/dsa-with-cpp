#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &inputStack, int number)
{
    // & base condition
    if (inputStack.empty())
    {
        inputStack.push(number);
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // * RECURSIVE CALL
    solve(inputStack, number);

    inputStack.push(num);
}

void insertAtBottom(stack<int> &inputStack, int number)
{
    solve(inputStack, number);
}

int main()
{
    stack<int> inputStack;
    inputStack.push(5);
    inputStack.push(8);
    inputStack.push(12);
    insertAtBottom(inputStack, 9);
    cout << "top element: " << inputStack.top() << endl;
    while(!inputStack.empty())
    {
        int num = inputStack.top();
        cout << num << ", ";
        inputStack.pop();
    } 
}