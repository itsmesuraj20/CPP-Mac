#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // Left Subtree
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Right Subtree˘
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}