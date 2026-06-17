//Height of the Binary Tree

class Node {
    int n ; 
    Node (int n){
        int data = n;
        root = data;
        left = root->null;
        right = root ->null;
    }
}

int heightofTree(Node *root ,Node *left, Node * ){
    
    if(root == Nullptr) return 0;

    int lh = heightofTree(root ->left);
    int rh = heightofTree (root -> right);

    return 1 + max(lh,rh);
    
}