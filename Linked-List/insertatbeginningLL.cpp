#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};


Node *inserAtBegin(Node *head , int x){
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

int main(){
    int x;
    cout<<"Enter the Node Value of the Linked List: " <<endl;
    cin>>x;

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    Node *curr = inserAtBegin(head , x);

    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr ->next;
    }
return 0;
}