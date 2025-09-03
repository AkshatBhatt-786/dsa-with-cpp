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

TreeNode* minValue(TreeNode* root)
{
    TreeNode* temp = root;
    while(temp -> left != NULL)
    {
        temp = temp -> left;
    }
    return temp;
}

TreeNode* maxValue(TreeNode* root)
{
    TreeNode* temp = root;
    while(temp -> right != NULL)
    {
        temp = temp -> right;
    }
    return temp;
}

TreeNode* inorderPredessor(TreeNode* root, TreeNode* p)
{
    TreeNode* predecessor = NULL;

    while(root != NULL)
    {
        if (p->data <= root->data)
            root = root -> left;
        else 
        {
            predecessor = root;
            root = root -> right;
        }
    }
    return predecessor;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
{
    TreeNode* successor = NULL;

    while(root != NULL)
    {
        if (p -> data >= root->data)
            root = root->right;
        else
        {
            successor = root;
            root = root->left; 
        }
    }
    return successor;
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

void inorder(TreeNode* &root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << ", ";
    inorder(root->right);
}

void preorder(TreeNode* &root)
{
    if (root == NULL)
        return;
    cout << root->data << ", ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* &root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ", ";
}

bool nodeIsPresent(TreeNode* root, int target)
{
    TreeNode* temp = root;
    while(temp != nullptr)
    {
        if (temp -> data == target) return true;
        else if (temp -> data > target) temp = temp->left;
        else temp = temp -> right;
    }
    return false;
}

TreeNode* getTargetNode(TreeNode* root, int target)
{
    TreeNode* temp = root;
    while(temp != nullptr)
    {
        if (temp -> data == target) return temp;
        else if (temp -> data > target) temp = temp->left;
        else temp = temp -> right;
    }
    return NULL;
}

TreeNode* deleteFromBST(TreeNode* root, int target)
{
    // base case
    if (root == NULL)
        return root;
    
    if (root -> data == target)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
        delete root;
        return NULL;
        }
        
        // 1 child

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        if (root->right != NULL && root->left == NULL)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int minVal = minValue(root->right) -> data;
            root -> data = minVal;
            root -> right = deleteFromBST(root->right, minVal);
        }
    } else if (root -> data > target)
    {
        root->left = deleteFromBST(root->left, target);
        return root;
    }
    else 
        root->right = deleteFromBST(root->right, target);
        return root;
}

int main()
{
    TreeNode* root = NULL;
    cout << "Enter data to create BST Tree" << endl;
    takeInput(root);
    root = deleteFromBST(root, 30);
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);
    cout << "Inorder Traversal: " << endl;
    inorder(root);
    cout << "\nPreorder Traversal: " << endl;
    preorder(root);
    cout << "\nPostorder Traversal: " << endl;
    postorder(root); 
    cout << endl;
    cout << "110 is present: " << (nodeIsPresent(root, 110) ? "yes" : "no") << endl;
    cout << "30 is present: " << (nodeIsPresent(root, 30) ? "yes" : "no") << endl;
    cout << endl;
    cout << "Inorder successor of 3 is: ";
    TreeNode* temp = getTargetNode(root, 50);
    TreeNode* sucessor = inorderSuccessor(root, temp);
    cout << sucessor -> data;
    cout << endl;
    cout << "Inorder predecessor of 3 is: ";
    TreeNode* predecessor = inorderPredessor(root, temp);
    cout << predecessor -> data;
    return 0;
}