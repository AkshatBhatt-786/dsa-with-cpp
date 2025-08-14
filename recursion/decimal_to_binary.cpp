#include <iostream>
#include <stack>
using namespace std;

void get_binary(int n, stack<int> &st) {
    if (n == 0) return;
    st.push(n % 2);
    get_binary(n / 2, st);
}

int main() {
    int n;
    stack<int> st;
    cout << "Enter decimal number: ";
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    get_binary(n, st);

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
