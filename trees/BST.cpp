#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};


Node* insertIntoBST(Node* root, int data)
{
    if (root == nullptr)
    {
        return new Node(data);
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

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    int cnt = 0;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cnt+=1;
            cout << endl;
            if (!q.empty())
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
    cout << "Height of Binary Tree : " << cnt;
}

void inorder(Node* root)
{
    if (root == nullptr) 
    {
        return;
    }
    inorder(root->left, count);
    cout << root->data << " ";
    inorder(root->right, count);
}

int main()
{
    Node* root = nullptr;

    int n;
    cout << "Enter number of Nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        root = insertIntoBST(root, data);
    }

    cout << "Inorder Traversal of BST (sorted): ";
    int count=0;
    inorder(root, count);
    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);
    cout << count;
    return 0;
}
