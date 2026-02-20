#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temps) {
    int n = temps.size();
    vector<int> ans(n, 0);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temps[i] > temps[st.top()]) {
            int prevIndex = st.top();
            st.pop();
            ans[prevIndex] = i - prevIndex;
        }
        st.push(i);
    }

    return ans;
}

int main() {
    vector<int> temps = {73,74,75,71,69,72,76,73};
    vector<int> res = dailyTemperatures(temps);

    for (int x : res) cout << x << " ";
    return 0;
}