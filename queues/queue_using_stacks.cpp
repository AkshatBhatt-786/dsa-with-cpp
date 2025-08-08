#include <bits/stdc++.h>
using namespace std;

// =========================================
// Problem 1: Implement Queue using Two Stacks (Easy)
// =========================================
/*
Problem Statement:
Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue:
- push(int x): Push element x to the back of the queue.
- pop(): Removes the element from the front of the queue and returns it. If the queue is empty, return -1.
- peek(): Get the front element. If the queue is empty, return -1.
- empty(): Returns true if the queue is empty, false otherwise.

Example:
Input:
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output:
[null, null, null, 1, 1, false]
Explanation:
MyQueue queue = new MyQueue();
queue.push(1); // queue is [1]
queue.push(2); // queue is [1, 2] (1 is front)
queue.peek();  // return 1
queue.pop();   // return 1, queue is [2]
queue.empty(); // return false

Constraints:
1 <= number of operations <= 100
-10^9 <= x <= 10^9
Only standard stack library is allowed (no queue library).
*/

class MyQueue {
private:
    stack<int> s1, s2; // s1 for input, s2 for output
    
    // Transfer all elements from s1 to s2
    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    MyQueue() {}

    // Push element to the back of the queue
    void push(int x) {
        s1.push(x);
    }

    // Removes element from front and returns it
    int pop() {
        if (s2.empty()) transfer();
        if (s2.empty()) return -1; // queue empty
        int frontVal = s2.top();
        s2.pop();
        return frontVal;
    }

    int peek() {
        if (s2.empty()) transfer();
        if (s2.empty()) return -1;
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << "\n"; 
    cout << q.pop() << "\n";  
    cout << (q.empty() ? "true" : "false") << "\n"; 
    return 0;
}
