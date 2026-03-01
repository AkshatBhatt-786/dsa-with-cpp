// LeetCode 113 - Path Sum II

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (!root) return;

        path.push_back(root->val);

        if (!root->left && !root->right && targetSum == root->val) {
            result.push_back(path);
        }

        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);

        path.pop_back(); // backtrack
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }
};