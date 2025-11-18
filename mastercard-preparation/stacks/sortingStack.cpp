#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void sortedInsert(stack<int> &st, int num)
{
    if (st.empty() || (!st.empty() && (st.top() < num)))
    {
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();

    sortedInsert(st, num);
    st.push(n);
}

void sortStack(stack<int> &st)
{
    if(st.empty()) {
        return;
    }

    int num = st.top();
    st.pop();

    sortStack(st);
    sortedInsert(st, num);
}


int main()
{
    stack<int> st;
    vector<int> vec;
    st.push(10);
    st.push(14);
    st.push(12);
    st.push(15);
    sortStack(st);
    int n = st.size();
    stack<int> tmp;
    while (!st.empty()) {
        tmp.push(st.top());
        st.pop();
    }
    while (!tmp.empty()) {
        cout << tmp.top();
        tmp.pop();
        if (!tmp.empty()) cout << ", ";
    }
    // while(!st.empty())
    // {
    //     cout << st.top() << ", ";
    //     st.pop();
    // }
}
