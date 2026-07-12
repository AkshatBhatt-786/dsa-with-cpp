// Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.

// A substring is a contiguous sequence of characters within a string.

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

bool containsPatternBitwise(const string& word, const string& pattern) {
    size_t m = pattern.size();
    if (m == 0) return true;

    size_t blocks = (m + 63) / 64;
    vector<vector<uint64_t>> mask(256, vector<uint64_t>(blocks, 0ULL));

    for (size_t j = 0; j < m; ++j) {
        unsigned char c = static_cast<unsigned char>(pattern[j]);
        mask[c][j / 64] |= (1ULL << (j % 64));
    }

    vector<uint64_t> state(blocks, 0ULL);

    for (char ch : word) {
        unsigned char c = static_cast<unsigned char>(ch);
        uint64_t carry = 1ULL;

        for (size_t b = 0; b < blocks; ++b) {
            uint64_t nextCarry = state[b] >> 63;
            state[b] = ((state[b] << 1) | carry) & mask[c][b];
            carry = nextCarry;
        }

        size_t lastBlock = (m - 1) / 64;
        uint64_t lastBit = 1ULL << ((m - 1) % 64);
        if (state[lastBlock] & lastBit) {
            return true;
        }
    }

    return false;
}

int numOfStrings(const vector<string>& patterns, const string& word) {
    int count = 0;
    for (const auto& pattern : patterns) {
        if (containsPatternBitwise(word, pattern)) {
            ++count;
        }
    }
    return count;
}