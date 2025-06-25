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


Node *insertAtEnd(Node *head ,int n){
    Node *temp = new Node(n);
    
    //Edge Case 1 : If the LinkedList is empty
    if(head == NULL) return temp;
    
    // Edge Case 2 : If the LinkedList has only one Node
    if(head->next ==NULL){
        head ->next = temp;
        return head;
    }

    //General Case
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }

    curr ->next = temp;
    return head ;
}
int main(){
    int n;
    cout<<"Enter the value of Node that need to be inserted in the end of the LinkedList"<<endl;
    cin>>n;

    Node *head = new Node (10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout<<"Before Insertion"<<endl;
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;

    head = insertAtEnd(head,n);

    cout<<"After Insertion"<<endl;
    curr = head;

    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;

    return 0;
}