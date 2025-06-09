//Displaying Linkedlist using recursion
#include<bits/stdc++.h>
using namespace std;
// Node structure
class Node{
    public:
    int data;
    Node *next ;
    Node(int x){
        data = x;
        next = NULL;
    }
};
// Function to display linked list using recursion
void recursivePrint(Node *head) {
    if(head == NULL){
        return ;
    }

    cout<<head -> data << " ";
    recursivePrint(head -> next);
}
// Function to display linked list using recursion
int main(){
    Node *head = new Node(1);
    head ->next = new Node(2);
    head ->next ->next = new Node(3);
    head ->next ->next ->next = new Node(4);

    recursivePrint(head);
    return 0;
//End of code
}