#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st; // store indices

    for (int i = 0; i < n; i++) {

        // Pop all smaller or equal prices
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }

        // If stack empty → span = i + 1
        if (st.empty()) span[i] = i + 1;
        else span[i] = i - st.top();

        st.push(i);
    }

    return span;
}

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans = stockSpan(prices);

    for (int x : ans) cout << x << " ";
    return 0;
}