#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int i = 0; // pointer for current character

    int calculate(string s) {
        i = 0; // reset pointer for each call
        return eval(s);
    }

private:
    int eval(string &s) {
        long result = 0;
        long num = 0;
        int sign = 1; // 1 for +ve, -1 for -ve

        while (i < s.size()) {
            char cc = s[i++];

            if (isdigit(cc)) {
                num = num * 10 + (cc - '0');
            }
            else if (cc == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }
            else if (cc == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }
            else if (cc == '(') {
                num = eval(s); // recursion for sub-expression
            }
            else if (cc == ')') {
                result += sign * num;
                return result; // return from current recursion
            }
            else if (cc == ' ') {
                continue; // skip spaces
            }
        }
        result += sign * num; // add last number
        return result;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter expression: ";
    getline(cin, s);

    cout << "Result: " << sol.calculate(s) << endl;
    return 0;
}
