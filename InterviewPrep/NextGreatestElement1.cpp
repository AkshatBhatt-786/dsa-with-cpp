#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> st;  // monotonic decreasing stack

    // Process nums2
    for (int num : nums2) {
        while (!st.empty() && num > st.top()) {
            nextGreater[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    // Remaining elements have no next greater
    while (!st.empty()) {
        nextGreater[st.top()] = -1;
        st.pop();
    }

    // Build result for nums1
    vector<int> result;
    for (int num : nums1) {
        result.push_back(nextGreater[num]);
    }

    return result;
}

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for (int x : ans) cout << x << " ";
    return 0;
}