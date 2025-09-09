#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        bool leftThreadedValue;
        bool rightThreadedValue;

        Node(int x)
        {
            data = x;
            left = nullptr;
            right = nullptr;
            leftThreadedValue = true;
            rightThreadedValue = true;
        }
};

class TBT
{
    public:
        Node* root;
    
    TBT()
    {
        root=NULL;
    }

    void insertInTBT(int x)
    {
        Node* nn = new Node(x);
        if (root == NULL)
        {
            root = nn;
            return;
        }
        Node* current = root;
        while (true)
        {
            if (x < current->data)
            {
                if (current->leftThreadedValue)
                {
                    nn->left = current->left;
                    nn->right = current;
                    current->left = nn;
                    current->leftThreadedValue = false;
                    break;
                }
                else
                {
                    current = current->left;
                }
            }
            else if (x > current->data)
            {
                if (current->rightThreadedValue)
                {
                    nn->right = current->right;
                    nn->left = current;
                    current->right = nn;
                    current->rightThreadedValue = false;
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
            else
            {
                break;
            }
        }
    }
};

int main()
{
    TBT tbt;
    tbt.insertInTBT(50);
    tbt.insertInTBT(40);
    tbt.insertInTBT(30);
    tbt.insertInTBT(25);
    tbt.insertInTBT(75);
    tbt.insertInTBT(65);
    tbt.traversal();
}