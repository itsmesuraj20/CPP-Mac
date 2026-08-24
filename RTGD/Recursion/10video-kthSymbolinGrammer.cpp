#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/k-th-symbol-in-grammar/description/
// Official question

int solve(int n , int k){
    if(n == 1 && k == 1){
        return 0 ;
    }

    int mid = pow(2,n-1) / 2 ; 

    if(k <= mid ){
        return solve(n-1,k);
    }

    else { 
        return !solve(n-1,k-mid);
    }
}


int main(){
    int n , k ;
    cin>>n>>k;
    cout<<"Enter N : " << endl;
    cout<<"Enter K : " << endl;

    cout<<solve(n,k)<<endl;

    return 0;
}