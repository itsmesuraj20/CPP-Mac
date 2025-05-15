#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }   
};

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree
// This is a simple implementation of pre-order traversal of a binary tree.
// The function recursively processes the root node, then visits the left subtree, and finally the right subtree.