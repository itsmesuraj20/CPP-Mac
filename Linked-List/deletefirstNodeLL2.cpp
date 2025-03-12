    //delete the last node from LL
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


     Node *deletefromLast(Node *head){
        if(head == nullptr || head->next == nullptr) 
            return nullptr;

        Node *curr = head;
        while(curr->next->next != nullptr){
            curr = curr->next;
        }

        delete curr->next;
        return head;
     }

     void printLL(Node* curr){
        while(curr != nullptr ){
            cout<<curr->data<< " ";
            curr = curr->next;
        }
     }

    int main(){

        Node *head = new Node(10);
        head->next = new Node(20);
        head->next->next = new Node(30);
        head->next->next->next = new Node(40);   

        Node *curr = deletefromLast(head);

        printLL(curr);
        return 0;
    }