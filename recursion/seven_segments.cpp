#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Segments {
    bool a, b, c, d, e, f, g;
};

// 7-segment patterns: a, b, c, d, e, f, g
Segments digits[10] = {
    {1,1,1,1,1,1,0}, // 0
    {0,1,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,1}, // 2
    {1,1,1,1,0,0,1}, // 3
    {0,1,1,0,0,1,1}, // 4
    {1,0,1,1,0,1,1}, // 5
    {1,0,1,1,1,1,1}, // 6
    {1,1,1,0,0,0,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}  // 9
};

int main() {
    string input;
    cout << "Enter number: ";
    cin >> input;

    // Validate input (must be digits only)
    for (char ch : input) {
        if (ch < '0' || ch > '9') {
            cout << "Invalid input — digits only.\n";
            return 0;
        }
    }

    cout << "a b c d e f g\n";

    // For each digit in input
    for (char ch : input) {
        int num = ch - '0';
        Segments s = digits[num];
        cout << s.a << " " << s.b << " " << s.c << " " 
             << s.d << " " << s.e << " " << s.f << " " << s.g << "\n";
    }
}
