#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

int main(){

    
    //adding the value to the Linked List (Long way of add the value)
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head ->next = temp1;
    temp1 ->next = temp2;
    //                                  OR    

    //adding the value to the Linked List (Short way of add the value)
    Node *head = new Node(10); 
    head ->next = new Node(20);
    head ->next ->next = new Node(30);

    //traversal for the linked list
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<"_";
        curr = curr->next;
    }

    return 0;
}