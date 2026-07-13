// 1291. Sequential Digits

// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            vector<int> result;
            // We generate all sequential digit numbers by taking substrings
            // of the fixed string "123456789". Each valid substring is a
            // sequential number with increasing digits.
            string base = "123456789";

            // Compute the number of digits in low and high to bound the length.
            int minLen = to_string(low).length();
            int maxLen = to_string(high).length();

            for (int len = minLen; len <= maxLen; ++len) {
                for (int start = 0; start + len <= (int)base.length(); ++start) {
                    int value = stoi(base.substr(start, len));
                    if (value > high) {
                        // Since further values with the same length will only be larger,
                        // we can stop this inner loop early.
                        break;
                    }
                    if (value >= low) {
                        result.push_back(value);
                    }
                }
            }

            return result;
        }
};

// Time Complexity: O(1) for fixed digit range, or more generally O(d^2) where d
// is the number of digits in high, because we generate a constant set of
// sequential-digit candidates from "123456789".
// Space Complexity: O(k), where k is the number of output values, since
// we store only the result list of sequential digit numbers.
