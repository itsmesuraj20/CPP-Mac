// Insert at the nth pos

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *insertatNth(Node *head, int pos, int data)
{
    Node *temp = new Node(data);
    if (pos == 0)
        return temp;

    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }

    Node *curr = head;
    for (int i = 0; i < pos - 2 && curr != nullptr; i++)
    {
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        cout << "Position out of range" << endl;
        return head;
    }

    temp->next = curr->next;
    curr->next = temp;
    return head;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Node *curr = insertatNth(head, 6, -999);
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}