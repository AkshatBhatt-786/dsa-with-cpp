#include <unordered_map>
#include <iostream>
using namespace std;

/*
Problem Statement:
Given a string, find the first non-repeating character in it and return its index.
If it does not exist, return -1.

Example 1:
Input:  "loveleetcode"
Output: 2
Explanation: 'v' is the first character that does not repeat.

Example 2:
Input:  "aabb"
Output: -1
Explanation: All characters repeat, so no unique character exists.
*/

int firstUniqueChar(string s)
{
    unordered_map<char, int> freq;

    // Step 1: count frequency of each character
    for (char c : s) {
        freq[c]++;
    }

    // Step 2: find the first character with freq = 1
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]] == 1) {
            return i;
        }
    }

    return -1; // no unique character
}

int main()
{
    string s = "loveleetcode";
    cout << "First non-repeating character index = " 
         << firstUniqueChar(s) << endl;
    return 0;
}
