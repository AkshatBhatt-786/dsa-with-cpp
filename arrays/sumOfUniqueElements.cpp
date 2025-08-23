#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Problem Statement:
Given an array of integers, find the sum of all elements that appear exactly once.

Example:
Input:  [1, 3, 3, 4, 5, 5]
Unique elements (occurring only once) = {1, 4}
Sum = 1 + 4 = 5
Output: 5
*/

int sumOfUniqueElements(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;  // count frequency of each element
    }

    int sum = 0;
    for (auto& entry : freq) {
        int num = entry.first;
        int count = entry.second;
        if (count == 1) sum += num;
    }


    return sum;
}

int main() {
    vector<int> arr = {1, 3, 5, 3, 5, 2};

    int result = sumOfUniqueElements(arr);

    cout << "Sum of unique elements = " << result << endl;

    return 0;
}
