#include<bits/stdc++.h>
using namespace std;

int fib(int n ){

    // TC :O(2^n);
    // SC : O(n);
    if( n <= 0) return 0;
    if( n == 1 ) return 1;
    return fib(n-1)+fib(n-2);

}

int fib(int n){

    
}

int main(){

    int n = 10;

    cout<<fib(n)<<endl;
    return 0;

}