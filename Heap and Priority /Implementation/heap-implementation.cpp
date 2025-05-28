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
    return 0;
}