#include<iostream>
using namespace std;

class Node {
public : 
    int data;
    Node* left;
    Node* right;

    Node (int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *treeImp(Node * root){
    cout<<"Enter the data to be inserted in Binary Tree"<<endl;
    int data;
    cin>>data ; 
    root = new Node (data);

    if(data == -1) return NULL;

    cout<<"Enter the data to be inserted in left "<< data<< endl;
    root->left = treeImp(root->left);
    cout<<"Enter the data to be inserted in right "<<data<<endl;
    root->right = treeImp(root->right);


    return root;
}

int main (){
    Node *root = NULL;

    root = treeImp(root);

    return 0;

}