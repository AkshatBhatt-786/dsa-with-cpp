/*
    Problem: Climbing Stairs With 3 Steps

    You are climbing a staircase. It takes exactly `n` steps to reach the top.
    Each time, you can climb either 1 step, 2 steps, or 3 steps.
    Return the number of distinct ways you can reach the top.

    Implement the solution using recursion.

    Example 1:
    Input: n = 3
    Output: 4
    Explanation: There are 4 ways to climb to the top:
        1. 1 step + 1 step + 1 step
        2. 1 step + 2 steps
        3. 2 steps + 1 step
        4. 3 steps

    Example 2:
    Input: n = 4
    Output: 7
    Explanation: There are 7 ways to climb to the top.

    Constraints:
    0 <= n <= 30
*/

#include <iostream>
using namespace std;

int jump(int n) {
    if (n < 0)  return 0;
    if (n == 0) return 1;
    return jump(n-1) + jump(n-2) + jump(n-3);
}

int main() {
    int n;
    cout << "Enter number of steps: ";
    cin >> n;
    cout << "Number of ways: " << jump(n);
    return 0;
}
