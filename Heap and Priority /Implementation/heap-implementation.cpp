#include<bits/stdc++.h>
using namespace std;
//Heap Implementation
//Heap is a special tree-based data structure that satisfies the heap property.

//In a max heap, for any given node I, the value of I is greater than or equal to the values of its children.
int main(){
    //Creating a max heap
    priority_queue<int> maxHeap;

    
    //Inserting elements into the max heap
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(30);

    //Printing the maximum element
    cout << "Maximum element: " << maxHeap.top() << endl;

    //Removing the maximum element
    maxHeap.pop();

    //Printing the new maximum element
    cout << "New maximum element: " << maxHeap.top() << endl;
    //Checking if the heap is empty
    if (maxHeap.empty()) {
        cout << "Heap is empty" << endl;
    } else {
        cout << "Heap is not empty" << endl;
    }
    //Printing the size of the heap
    cout << "Size of heap: " << maxHeap.size() << endl;

    //Iterating through the heap elements
    cout << "Heap elements: ";
    priority_queue<int> tempHeap = maxHeap; // Create a copy to iterate
    while (!tempHeap.empty()) {
        cout << tempHeap.top() << " ";
        tempHeap.pop();
    }
    cout << endl;
    //Clearing the heap
    while (!maxHeap.empty()) {
        maxHeap.pop();
    }
    cout << "Heap cleared." << endl;
    if (maxHeap.empty()) {
        cout << "Heap is empty after clearing." << endl;
    } else {
        cout << "Heap is not empty after clearing." << endl;
    }

    //Printing the size of the heap after clearing
    cout << "Size of heap after clearing: " << maxHeap.size() << endl;

    //Heap is a complete binary tree, so we can also use an array to represent it.
    vector<int> heapArray = {30, 20, 10, 5}; // Example array representation of a max heap
    cout << "Array representation of heap: ";
    for (int i = 0; i < heapArray.size(); i++) {
        cout << heapArray[i] << " ";
    }
    cout << endl;

    //Heap sort using the array representation
    sort(heapArray.begin(), heapArray.end(), greater<int>());
    cout << "Sorted array using heap sort: ";
    return 0;
}