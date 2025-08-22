#include <iostream>
using namespace std;

void inorder(node* &root, &count) 
{
    if (root == NULL) return;
    inorder(root -> left, count);

    if (root -> left == NULL && root -> right == NULL) count++;
    cout << root -> data << ", ";
    inorder(root -> right, count);
}

