#include<iostream>
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

int searchRecursively(Node *head, int x ,int pos = 1){
	
	if(head == nullptr) return -1;

	if(head->data == x){
		return pos;
	}

	return searchRecursively(head->next , x,pos + 1);
}

int main(){
	Node *head = new Node (10);
	head->next = new Node (20);
	head->next->next = new Node(30);
	head->next->next->next = new Node(40);

	
	int pos = searchRecursively(head, 30);
	
	if(pos != -1)
	cout<<"Found"<<" "<<pos<<endl;

	else
	cout<<"Not Found"<<endl; 

	return 0;
}