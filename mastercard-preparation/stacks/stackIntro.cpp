// creation of stack
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;

    st.push(10);
    st.push(15);
    st.push(20);
    cout << "top element: " << st.top() << endl;
    st.pop();
    st.pop();
    cout << "top element: " << st.top() << endl;
    if (st.empty()) cout << "stack is empty!";
    else cout << "stack is not empty!";
}