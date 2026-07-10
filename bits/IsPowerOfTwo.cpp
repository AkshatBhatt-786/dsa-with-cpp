// 231. Power of Two
// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x.

#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // Negative numbers and zero are not powers of two
        return (n & (n - 1)) == 0; // A power of two has exactly one bit set in its binary representation
    }
};