#include<bits/stdc++.h>
using namespace std;

class Node {

    public:
    int data;
    Node *next;

    Node(int x){
        data = x;
        next = NULL; 
    }
};

Node* implementation(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    return head;
}

int main(){
    Node *head = implementation();

    Node *curr = head;
    while(curr!= NULL){
        cout<<curr->data<<" ";
        curr= curr->next;
    }

    //Clean up after the usage of the linked list (deleting the nodes)
    // Node *temp = head;
    // while(temp!=NULL){
    //     Node *next = head;
    //     delete temp;
    //     temp = next;
    // }



    return 0;
}