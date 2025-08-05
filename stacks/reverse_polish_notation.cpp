#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class RPNCalculator {
private:
    string expr;
    stack<int> st;

public:
    RPNCalculator(string s) {
        expr = s;
    }

    int evaluate(int a, int b, char opr) {
        if (opr == '+') return a + b;
        if (opr == '-') return a - b;
        if (opr == '*') return a * b;
        if (opr == '/') return a / b;
        if (opr == '%') return a % b;
        return 0;
    }

    void perform_rpn() {
        for (char cc : expr) {
            if (cc == ' ') continue; // <- ignore spaces
            if (cc == '+' || cc == '/' || cc == '-' || cc == '*' || cc == '%') {
                if (st.size() < 2) {
                    cout << "Syntax Error: Not enough operands.\n";
                    return;
                }
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int result = evaluate(a, b, cc);
                cout << a << " " << cc << " " << b << " = " << result << endl;
                st.push(result);
            } else if (isdigit(cc)) {
                st.push(cc - '0'); // convert char to int
            } else {
                cout << "Syntax Error: Invalid character '" << cc << "'\n";
                return;
            }
        }

        if (st.size() == 1) {
            cout << "Evaluation of \"" << expr << "\" is " << st.top() << endl;
        } else {
            cout << "Syntax Error: Too many operands.\n";
        }
    }
};

int main() {
    string input;
    cout << "Enter RPN expression (e.g. 5 2 * 3 +): ";
    getline(cin, input);

    RPNCalculator calc(input);
    calc.perform_rpn();

    return 0;
}
