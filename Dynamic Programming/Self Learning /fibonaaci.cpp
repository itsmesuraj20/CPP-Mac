#include<bits/stdc++.h>
using namespace std;

// Commit : Learning : Fibonacci Self Learning

int fib(int n ){

    // TC :O(2^n);
    // SC : O(n);

    if( n <= 1 ) return n;

    return fib(n-1)+fib(n-2);
}

int fib(int n,vector<int> &dp){
    
    if( n <= 1 ) return n;

    if( dp[n] != -1 ) return dp[n] ;

    return dp[n] = fib(n-1,dp)+fib(n-2,dp);

}

int main(){

    int n = 10;

    vector<int> dp(n,-1);

    cout<<fib(n)<<endl;
    cout<<fib(n,dp)<<endl;

    return 0;

}