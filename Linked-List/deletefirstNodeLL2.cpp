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

Node *deleteFirst(Node *head){
    if(head == nullptr){
        return nullptr;
    }

    Node *temp = head->next;
    delete head;
    return temp;
}

void printLL(Node *curr){
    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);     

    Node *curr = deleteFirst(head);
    printLL(curr);
    
    return 0;
}