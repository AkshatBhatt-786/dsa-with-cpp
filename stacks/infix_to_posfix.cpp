#include <iostream>
#include <stack>
using namespace std;

int prec(char opr) {
    if (opr == '+' || opr == '-') return 1;
    if (opr == '*' || opr == '/') return 2;
    if (opr == '^' || opr == '$') return 3;
    return 0;
}

string infix_to_postfix(string infix_exp) {
    string res = "";
    stack<char> st;

    for (char cc : infix_exp) {
        if (cc >= 'a' && cc <= 'z' || cc >= 'A' && cc <= 'Z' || isdigit(cc)) {
            res += cc;
        }
        else if(cc == '(') {
            st.push(cc);
        }
        else if(cc == ')') {
            while(st.top() != '(') {
                res += st.top(); st.pop();
            }
            st.pop();
        } 
        else {
            while(!st.empty() && prec(st.top()) >= prec(cc)) {
                res += st.top();
                st.pop();
            }
            st.push(cc);
        }   
    }

    while(!st.empty()) {
        res += st.top(); st.pop();
    }

    return res;
}

int main() {
    string infix;
    cout << "Enter infix expression (e.g) A*(B+C): ";
    cin >> infix;

    string postfix = infix_to_postfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}