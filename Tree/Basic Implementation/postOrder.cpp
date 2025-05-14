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
void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree
// This is a simple implementation of post-order traversal of a binary tree.
// The function recursively visits the left subtree, then the right subtree, and finally processes the root node.
// The output will be the post-order traversal of the binary tree.