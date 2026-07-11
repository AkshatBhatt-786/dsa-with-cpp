#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) return "";

    int minLen = strs[0].size();
    for (const auto& s : strs) {
        minLen = min(minLen, (int)s.size());
    }

    int low = 0, high = minLen;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        string prefix = strs[0].substr(0, mid);
        bool allMatch = true;
        for (size_t i = 1; i < strs.size(); ++i) {
            if (strs[i].compare(0, mid, prefix) != 0) {
                allMatch = false;
                break;
            }
        }
        if (allMatch) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    return strs[0].substr(0, low);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> strs;
    strs.reserve(n);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        strs.push_back(s);
    }

    cout << longestCommonPrefix(strs);
    return 0;
}
