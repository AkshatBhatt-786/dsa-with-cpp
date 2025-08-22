#include <iostream>
#include <queue>
using namespace std;

class node {

public:
    int data;
    node* left;
    node* right;

    node(int data) 
    {
        this -> data = data;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

void inorder(node* root) 
{
    if (root == NULL) return;
    inorder(root -> left);
    cout << root -> data << ", ";
    inorder(root -> right);
}

void preorder(node* root) 
{
    if (root == NULL) return;
    cout << root -> data << ", ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node* root)
{
    if(root == NULL) return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << ", ";
}

node* buildTree(node* root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1) return nullptr;

    cout << "Enter data for inserting in left node of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right node of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) // purana level complete traverse ho chuka hai 
        {
            cout << endl;
            if (!q.empty()) // queue still has some child nodes
            {
                q.push(NULL);
            }
        } else 
        {
            cout << temp -> data << ", ";
            if (temp -> left) 
            {
                q.push(temp -> left);
            }
            if (temp -> right)
            {
                q.push(temp -> right);
            }
        }

    }
}
int main() 
{
    node* root = NULL;
    // creating a tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    // level order traversal
    levelOrderTraversal(root);
    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal : ";
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal : ";
    postorder(root);
    cout << endl;
    return 0;
}