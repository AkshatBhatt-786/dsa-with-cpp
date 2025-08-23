#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Problem Statement:
Given an array of integers nums and an integer target, return the indices 
of the two numbers such that they add up to the target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice. 
You can return the answer in any order.
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash; // stores value -> index
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        if (hash.find(complement) != hash.end()) {
            // found the pair
            return {hash[complement], i};
        }
        // store current number with index
        hash[nums[i]] = i;
    }
    return {}; // no solution (though guaranteed in problem)
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);
    cout << "Indices: [" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
