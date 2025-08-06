    // MinStack Problem

    /*
        You are asked to design a stack that supports:
        1. push(x)     - pushes x onto the stack
        2. pop()       - removes the top element
        3. top()       - gets the top element
        4. getMin()    - retrieves the minimum element in the entire stack

        All operations must be O(1) time.

        ----------------------------------------------------
        Let's go through this with a simple example:

        Input Operations:
        ["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
        Input Values:
        [[],          [5],    [3],    [7],    [],        [],    [],     []]

        Explanation:
        1. MinStack    --> create an empty stack
        2. push(5)     --> stack becomes: [5],     min = 5
        3. push(3)     --> stack becomes: [5, 3],  min = 3 (because 3 < 5)
        4. push(7)     --> stack becomes: [5, 3, 7], min = still 3
        5. getMin()    --> returns 3 (smallest so far)
        6. pop()       --> removes 7, stack becomes [5, 3]
        7. top()       --> returns 3 (top of stack)
        8. getMin()    --> still returns 3

        Now if we pop() again (removes 3), the stack becomes [5] and min becomes 5.

        ----------------------------------------------------

        The main challenge:
        - You need to remember what the *minimum* was at each stage.
        - Just storing values in one stack isn’t enough.
        - So, we typically use an extra stack to **track the minimums**.

        Think of it like:
        value_stack:    [5, 3, 7]
        min_stack:      [5, 3, 3]

        When you pop from value_stack, also pop from min_stack.
        So min_stack.top() always gives you the current minimum.
    */
    #include <iostream>
    #include <stack>
    using namespace std;

    class MinStack {
        stack<int> minStack;
        stack<int> mainStack;

    public:
        MinStack() {

        }
        int top() {
            if (!mainStack.empty()) return mainStack.top();
            return -1;
        }

        void push(int x) {
            mainStack.push(x);
            if (minStack.empty() || x <= minStack.top()) {
                minStack.push(x);
            }
        }

        int getMin() {
            if (!minStack.empty()) return minStack.top();
            return -1;
        }

        int pop() {
            if (!mainStack.empty()) {
                int top = mainStack.top();
                mainStack.pop();

                if (top == minStack.top()) minStack.pop();
            }
        }
    };

    int main() {
        MinStack ms;
        ms.push(10);
        ms.push(13);
        ms.push(3);
        ms.push(20);
        ms.pop(); // removes 20
        cout << "Top: " << ms.top() << endl;      // should be 3
        cout << "Min: " << ms.getMin() << endl;   // should be 3

        ms.pop(); // removes 3
        cout << "Top: " << ms.top() << endl;      // should be 13
        cout << "Min: " << ms.getMin() << endl;   // should be 10

    }