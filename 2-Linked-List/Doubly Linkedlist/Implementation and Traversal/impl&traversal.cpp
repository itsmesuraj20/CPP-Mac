#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Insert at beginning
    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Forward traversal
    void printForward()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *curr = head;
        cout << "Forward Traversal: ";
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    // Backward traversal
    void printBackward()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        cout << "Backward Traversal: ";
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

int main()
{
    DoublyLinkedList dll;

    // Insert some elements
    dll.insertAtHead(30);
    dll.insertAtHead(20);
    dll.insertAtHead(10);

    // Traverse both ways
    dll.printForward();  // Output: 10 20 30
    dll.printBackward(); // Output: 30 20 10

    return 0;
}