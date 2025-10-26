#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isPalidrome(string word) 
{
    stack<char> charStack;
    queue<char> charQueue;

    //  ** Push all characters to both stack and queue
    for (char c : word) {
        // Optional: Convert to lowercase for case-insensitive comparison
        // char lowerC = tolower(c);
        charStack.push(c);
        charQueue.push(c);
    }

    // Compare characters from stack (reverse order) and queue (original order)
    while (!charStack.empty() && !charQueue.empty()) {
        if (charStack.top() != charQueue.front()) {
            return false; // ^ Characters don't match - not a palindrome
        }
        charStack.pop();
        charQueue.pop();
    }

    return true;
}

int main() {
    cout << isPalidrome("bob");
    cout << isPalidrome("akshat");
    cout << isPalidrome("anna");
}