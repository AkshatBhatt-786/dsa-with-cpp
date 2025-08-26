#include <iostream>
using namespace std;

int solve(BinaryTreeNode<int> *root, int &i, int k)
{
    // base condition
    if (root == NULL)
        return -1;
    
    // L
    int left = solve(root->left, i, k);
    
    if(left != -1)
    {
        return left;
    }
    // N
    i++;

    if(i == k)
    {
        return root->data;
    }

    // R
    return solve(root->right, i, k);
}

int kthSmallest(BinaryTreeNode<int> *root, int &i, int k)
{
    int i=0;
    int ans = solve(root, i, k);
    return ans;
}
