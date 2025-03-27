#include<bits/stdc++.h>
using namespace std;

//Multi-Threading in C++
//Threading is a way to run multiple threads (smaller units of process) simultaneously.

int main(){
    //Creating a thread
    thread t1([](){
        cout << "Thread 1 is running" << endl;
    });

    //Joining the thread
    t1.join();

    //Creating another thread
    thread t2([](){
        cout << "Thread 2 is running" << endl;
    });

    //Joining the second thread
    t2.join();

    cout << "Main thread is running" << endl;

    return 0;
}
//TC : O(1)
//SC : O(1)