// approach 1:
//   inorder O(n)
//   BST properties check
//   return true or false


// approach 2:
// space and time complexity is O(H) and O(n);
#include <iostream>
using namespace std;

class BinaryTreeNode
{
public:
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;

    BinaryTreeNode(int data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
}

bool isBST(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
        return true;
    
    if (root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
        return false;
}

void validateBST(BinaryTreeNode<int> *root)
{
    return isBST(root, INT_MIN, INT_MAX);

}