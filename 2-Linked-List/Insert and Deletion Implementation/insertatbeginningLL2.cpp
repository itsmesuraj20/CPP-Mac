#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node *insertatBegin(Node *head, int x){
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

void printLL(Node *head){
    Node *curr = head;

    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

int main(){
    int nodeVal;
    cout<<"Enter the value of the node to be inserted at the beginning: ";
    cin>>nodeVal;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    
    Node *curr = insertatBegin(head,nodeVal);

    printLL(curr);
    return 0;
}