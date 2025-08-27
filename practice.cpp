#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

void LevelOrderTraversal(TreeNode* root)
{
    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        cout << temp -> data << ", ";
        if (temp -> left) q.push(temp -> left);
        if (temp -> right) q.push(temp -> right);
    }
}

TreeNode* insertIntoBST(TreeNode* root, int data)
{
    if (root == nullptr)
    {
        return new TreeNode(data);
    }

    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

TreeNode* buildTree(TreeNode* root)
{
    int d;
    cout << "Enter data: ";
    cin >> d;

    root = new TreeNode(d);
    // * Base condition
    if (d == -1) return NULL;

    // * Left Node 
    cout << "Enter data to insert at left of " << root -> data << endl;
    root -> left = buildTree(root->left);

    // * Right Node
    cout << "Enter data to insert at right of " << root -> data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

int main()
{
    TreeNode* root = NULL;
    root = insertIntoBST(root);
    LevelOrderTraversal(root);
    inorder(root);
}