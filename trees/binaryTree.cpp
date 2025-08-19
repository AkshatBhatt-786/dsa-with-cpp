#include <iostream>
using namespace std;

class node {

public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree 
{
public:
    node* first = nullptr;
    BinaryTree() 
    {
        first = nullptr;
    }

    void insertAtLeft(int data) {
        node* nn = new node(data);
        if (first == nullptr) {
            first = nn;
        }
        node* temp = first;
        while(temp -> left != nullptr) 
        {
            temp = temp -> left;
        }
        temp -> left = nn;
    }
}

