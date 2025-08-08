#include <bits/stdc++.h>
using namespace std;

// =========================================
// Problem 2: Number of Students Unable to Eat Lunch (Medium)
// =========================================
/*
Example:
students = [1,1,0,0], sandwiches = [0,1,0,1] → Output: 0
students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1] → Output: 3
*/

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);

    int index = 0, pass = 0;
    while (!q.empty() && pass < q.size()) {
        if (q.front() == sandwiches[index]) {
            q.pop();
            index++;
            pass = 0;
        } else {
            q.push(q.front());
            q.pop();
            pass++;
        }
    }
    return q.size();
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};
    cout << countStudents(students, sandwiches) << "\n"; 

    vector<int> students2 = {1,1,1,0,0,1};
    vector<int> sandwiches2 = {1,0,0,0,1,1};
    cout << countStudents(students2, sandwiches2) << "\n"; 
}
