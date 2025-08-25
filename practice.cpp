#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class node 
{
public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};


node* buildTree(node* root)
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    root = new node(data);

    if (data == -1) return nullptr;

    cout << "Enter data for left tree: " << root -> data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for right tree: " << root -> data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

int main()
{
    node* root = NULL;
    root = buildTree(root);
}
