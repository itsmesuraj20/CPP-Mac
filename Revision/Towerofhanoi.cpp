#include<bits/stdc++.h>
using namespace std;

void solve(int n , int source , int destination , int helper){

    if(n == 0 ) return ;

    if( n == 1 ) {
        cout<< source << " -> " << destination ; 
        return ; 
    } 

    solve( n - 1, source , helper , destination )
    cout<<"Move Disk " << source <<" to " << destination ;
    solve( n - 1, helper , destination , source);
}

int main(){

    int n

    return 0 ;
}