#include<bits/stdc++.h>
using namespace std;

// Commit : Learning : Fibonacci Self Learning

int fib(int n ){

    // TC :O(2^n);
    // SC : O(n);

    if( n <= 1 ) return n;

    return fib(n-1)+fib(n-2);
}

int fib(int n){

    if( n <= 1 ) return n;




}

int main(){

    int n = 10;

    cout<<fib(n)<<endl;
    return 0;

}