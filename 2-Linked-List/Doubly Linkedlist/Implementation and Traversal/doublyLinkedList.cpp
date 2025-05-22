#include<bits/stdc++.h>
using namespace std;
// Doubly Linked List Node structure
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};
// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    
public:
    DoublyLinkedList() : head(nullptr) {}
    
    // Insert at beginning
    void insertFront(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if(head) head->prev = newNode;
        head = newNode;
    }
    
    // Insert at end
    void insertEnd(int data) {
        if(!head) {
            insertFront(data);
            return;
        }
        
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        
        Node* newNode = new Node(data);
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    // Delete from front
    void deleteFront() {
        if(!head) return;
        
        Node* temp = head;
        head = head->next;
        if(head) head->prev = nullptr;
        delete temp;
    }
    
    // Delete from end
    void deleteEnd() {
        if(!head) return;
        if(!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        
        Node* temp = head;
        while(temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    
    // Display list forward
    void displayForward() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Display list backward
    void displayBackward() {
        if(!head) return;
        
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        
        while(temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    
    // Cleanup
    ~DoublyLinkedList() {
        while(head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    
    // Test operations
    dll.insertFront(10);
    dll.insertFront(20);
    dll.insertEnd(30);
    dll.insertEnd(40);
    
    cout << "Forward traversal: ";
    dll.displayForward();  // Output: 20 10 30 40
    
    cout << "Backward traversal: ";
    dll.displayBackward(); // Output: 40 30 10 20
    
    dll.deleteFront();
    dll.deleteEnd();
    
    cout << "After deletions (Forward): ";
    dll.displayForward();  // Output: 10 30
    
    return 0;
}