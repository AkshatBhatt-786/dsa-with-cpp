#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
private:
    const int MOD = 1e9 + 7;

    // Helper function to calculate Greatest Common Divisor
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    int subsequencePairCount(std::vector<int>& nums) {
        int maxVal = 0;
        for (int x : nums) {
            maxVal = std::max(maxVal, x);
        }

        // dp[g1][g2] stores the count of valid pairs with current GCDs g1 and g2
        std::vector<std::vector<int>> dp(maxVal + 1, std::vector<int>(maxVal + 1, 0));
        dp[0][0] = 1;

        // Precompute GCD values to keep the core loop ultra-fast
        std::vector<std::vector<int>> gcdMemo(maxVal + 1, std::vector<int>(maxVal + 1, 0));
        for (int i = 0; i <= maxVal; ++i) {
            for (int j = 0; j <= maxVal; ++j) {
                gcdMemo[i][j] = gcd(i, j);
            }
        }

        for (int x : nums) {
            // Using a next_dp matrix for the rolling array optimization technique
            std::vector<std::vector<int>> next_dp(maxVal + 1, std::vector<int>(maxVal + 1, 0));
            
            for (int g1 = 0; g1 <= maxVal; ++g1) {
                for (int g2 = 0; g2 <= maxVal; ++g2) {
                    if (dp[g1][g2] == 0) continue;
                    
                    long long currentWays = dp[g1][g2];

                    // Choice 1: Skip x entirely
                    next_dp[g1][g2] = (next_dp[g1][g2] + currentWays) % MOD;

                    // Choice 2: Include x in seq1
                    int n1 = (g1 == 0) ? x : gcdMemo[g1][x];
                    next_dp[n1][g2] = (next_dp[n1][g2] + currentWays) % MOD;

                    // Choice 3: Include x in seq2
                    int n2 = (g2 == 0) ? x : gcdMemo[g2][x];
                    next_dp[g1][n2] = (next_dp[g1][n2] + currentWays) % MOD;
                }
            }
            dp = std::move(next_dp);
        }

        // Sum up all pairs where both subsequences are non-empty (g > 0) and have matching GCDs
        long long ans = 0;
        for (int g = 1; g <= maxVal; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};