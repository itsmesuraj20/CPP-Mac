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

Node *insertatEnd(Node*head , int x){
    Node *curr = head;
    Node *temp = new Node(x);


    if(head == nullptr){
        return temp;
    }

    while(curr->next != nullptr){
        curr = curr ->next;
    }

    curr->next = temp;
    return head;
}

void printLL(Node *curr){
    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}


int main(){
    int nodeVal;
    cout<<"Enter the value of the node to be inserted at the end : "<<endl;
    cin>>   nodeVal;

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);    

    Node *curr = insertatEnd(head,nodeVal);
    printLL(curr);
    return 0;
}