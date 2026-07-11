// 5. Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.
// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letter

#include <iostream>
#include <string>   

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i); // Odd length palindrome
            int len2 = expandAroundCenter(s, i, i + 1); // Even length palindrome
            int len = std::max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

private:
    int expandAroundCenter(const std::string &s, int left, int right) {
        while (left >= 0 && right < static_cast<int>(s.length()) && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
