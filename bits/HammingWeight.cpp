// 191. Number of 1 Bits
// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += n & 1; // Increment count if the least significant bit is 1
            n >>= 1; // Right shift n by 1 to process the next bit
        }
        return count;
    }
};