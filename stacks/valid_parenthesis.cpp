#include <iostream>
#include <stack>
using namespace std;



bool is_valid_parenthesis(string exp) {
    stack<char> st;
    for (char cc : exp) {
        if (cc == '{' || cc == '(' || cc == '[') {
            st.push(cc);
        }
        else {
            if(st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((top != '{' && cc == '}') || (top != '(' && cc == ')') || (top != '[' && cc == ']')) return false;
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    if (is_valid_parenthesis(s)) { 
        cout << "valid parenthesis" << endl;
    }
    else 
    {
        cout << "not valid parenthesis" << endl; 
    }
}