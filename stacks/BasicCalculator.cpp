/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

-> 1 <= s.length <= 3 * 105
-> s consists of digits, '+', '-', '(', ')', and ' '.
-> s represents a valid expression.
-> '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
-> '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
-> There will be no two consecutive operators in the input.
-> Every number and running calculation will fit in a signed 32-bit integer.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    return 0;
}

int apply(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return 0;
}

int calculate(string s) {
    stack<int> nums;
    stack<char> ops;
    int n = s.size();
    int i = 0;

    while (i < n) {
        char c = s[i];

        if (isspace(c)) {
            i++;
            continue;
        }

        if (isdigit(c)) {
            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            nums.push(num);
            continue;
        }

        if (c == '(') {
            ops.push(c);
        } else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();
                nums.push(apply(a, b, op));
            }
            ops.pop(); // pop '('
        } else if (c == '+' || c == '-') {
            // handle unary minus
            if ((i == 0) || (s[i - 1] == '(')) {
                nums.push(0);
            }
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();
                nums.push(apply(a, b, op));
            }
            ops.push(c);
        }

        i++;
    }

    while (!ops.empty()) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        nums.push(apply(a, b, op));
    }

    return nums.top();
}

int main() {
    string s1 = "1+(10-1)-2";
    cout << calculate(s1) << endl;
    return 0;
}