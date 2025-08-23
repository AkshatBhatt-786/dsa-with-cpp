#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Problem Statement:
Given an array of integers, find the element that has the highest frequency 
(i.e., appears the most number of times).
If multiple elements have the same frequency, return any one of them.

Example:
Input:  [1, 3, 3, 4, 5, 5]
Frequencies: 1 → 1, 3 → 2, 4 → 1, 5 → 2
Highest frequency = 2 (elements 3 and 5)
Output: 5   (or 3, since both are valid)
*/

int mostFrequentElement(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }
    int maxFreq = 0;
    int element = arr[0];
    for (auto& entry : freq) {
        if (entry.second > maxFreq) {
            maxFreq = entry.second;
            element = entry.first;
        }
    }
    return element;
}

int main() {
    vector<int> arr = {1, 3, 3, 4, 5, 5};
    cout << "Most frequent element = " << mostFrequentElement(arr) << endl;
    return 0;
}
