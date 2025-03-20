#include<bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node *next;
    Node *prev;
    Node(int data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

int main(){

    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp1;
    temp1->prev = head;


    temp1->next = temp2;
    temp2->prev = temp1;

    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }

    return 0;
    
}