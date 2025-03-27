//Parallel Algorithms in C++
// Parallel algorithms are algorithms that can be executed in parallel, using multiple threads or processors.

// They are designed to take advantage of the parallel processing capabilities of modern hardware.

#include<bits/stdc++.h>
using namespace std;

//Parallel Algorithms in C++
int main(){
    //Creating a vector of integers
    vector<int> vec = {1, 2, 3, 4, 5};

    //Using parallel execution policy to transform the vector
    transform(vec.begin(), vec.end(), vec.begin(), [](int x) {
        return x * x;
    });

    //Printing the transformed vector
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
//TC : O(n)
//SC : O(1)
//Parallel algorithms can significantly improve the performance of certain tasks, especially when dealing with large datasets.