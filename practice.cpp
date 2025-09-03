#include <iostream>
#include <queue>
using namespace std;

class TreeNode 
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode(int data)
        {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
};

TreeNode* insertInBST(TreeNode* root, int data)
{
    // base condition
    if (root == NULL)
    {
        root = new TreeNode(data);
        return root;
    }

    if (data > root->data)
        root->right= insertInBST(root->right, data);
    else 
        root->left = insertInBST(root->left, data);
    
    return root;
}

void levelOrderTraversal(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << ", ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void takeInput(TreeNode* &root)
{
    int data;
    cin >> data;
    while(data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }
}

int main()
{
    TreeNode* root = NULL;
    cout << "Enter data to create BST Tree" << endl;
    takeInput(root);
    levelOrderTraversal(root);
    return 0;
}