#include<bits/stdc++.h>
using namespace std;


//Node Class for LinkedList 
class Node{
    public:

    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

//Function to delete first node of LinkedList
Node* deleteFirstNode(Node *head){

    if(head == NULL) return NULL;

    else{
        Node* temp = head->next;
        delete head;
        return temp;
    }
}


//Function to delete first node of LinkedList
int main(){
    Node *head = new Node (10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Node *curr = deleteFirstNode(head);

    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }

    return 0;

}