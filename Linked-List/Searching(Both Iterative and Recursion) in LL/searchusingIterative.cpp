#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

pair<Node*,int> search(Node *head ,int data){
    Node *curr = head;
    int c = 1;
    while(curr != nullptr){
        c++;
        if(curr->data == data){
            return make_pair(curr , c);
        }
        curr = curr->next;
    }
    return make_pair(nullptr , c);
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    pair<Node*,int>  curr = search(head, 20);
    if(curr.first != nullptr){
        cout << "Element found at : "<< curr.second << endl;
    }
    else{
        cout << "Element not found" << endl;
    }
    return 0;
}