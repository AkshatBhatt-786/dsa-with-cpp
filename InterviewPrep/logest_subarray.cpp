#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarray(vector<int>& arr) {
    unordered_map<int, int> mp;
    int sum = 0, maxLen = 0;

    mp[0] = -1;

    for(int i = 0; i < arr.size(); i++) {
        sum += (arr[i] == 0 ? -1 : 1);

        if(mp.find(sum) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {0,1,0,0,1,1,0};
    cout << longestSubarray(arr);
}