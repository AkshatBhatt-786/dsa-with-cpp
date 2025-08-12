#include <iostream>
using namespace std;

void getSubSequence(string str, int strIndex, string output) {
    // base condition
    if (strIndex == str.length()) {
        cout << output << endl;
        return;
    }

    // nahi lena
    getSubSequence(str, strIndex+1, output);

    // lena hai
    output.push_back(str[strIndex]);
    getSubSequence(str, strIndex+1, output);
}

int main() {
    string str = "abc";
    string output = "";
    getSubSequence(str, 0, output);
}