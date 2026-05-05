#include<bits/stdc++.h>
using namespace std;

// Commit : Learning : Fibonacci Self Learning

int fib(int n ){

    // TC :O(2^n);
    // SC : O(n);

    if( n <= 1 ) return n;

    return fib(n-1)+fib(n-2);
}


// Memoization : 

int fibMemoization(int n,vector<int> &dp){
    if( n <= 1 ) return n;

    if( dp[n] != -1 ) return dp[n] ;

    return dp[n] = fib(n-1,dp)+fib(n-2,dp);
}

int fibTabulation(int n ,vector<int> &dp)
{
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n  ; i++)
    {
       dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];

}

int main(){

    int n = 10;

    vector<int> dp(n,-1);

    cout<<fib(n)<<endl;
    cout<<fibMemoization(n,dp)<<endl;
    cout<<fibTabulation(n,dp)<<endl;

    return 0;

}