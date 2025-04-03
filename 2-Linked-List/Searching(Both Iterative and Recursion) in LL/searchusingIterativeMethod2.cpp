#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

void searchLL(Node *head, int data){

    if(head == nullptr){
        cout<<"Empty , cant perform search algo"<<endl;
        return;
    }


    Node *curr = head;
    bool ans = false;
    int c = 0;
    while(curr != nullptr){
        c++;
        if(curr->data == data){
            cout<<"Found at : "<< c << endl;
            ans = true;
            break;

        }
            curr = curr->next;
    }

    if(ans == false){
        cout<<"Not Found"<<endl;
    }
}

int main(){
    cout<<"Enter the data to be founded"<<endl;
    
    int data;
    cin>>data;

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    searchLL(head,data);

    
}