#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        long long x = llabs((long long)n);
        long long rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        long long diff = llabs((long long)n - rev);
        return (int)diff;
    }
};

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    Solution s;
    cout << s.mirrorDistance((int)n);
    return 0;
}

