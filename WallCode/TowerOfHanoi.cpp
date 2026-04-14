#include<bits/stdc++.h>
using namespace std;

// n :
// source :
// destination :
// helper : 



void solveTOH(int n , int source , int destination , int helper){
    if ( n == 0 ) return ;
    if ( n == 1 ) 
    {
    cout<< source << " -> " << destination ; 
    return ;
    }

    solve(n-1, source, helper , destination);
    cout<<" Move Disk " << source << " to " << destination ; 
    solve(n-1,helper , destination , source);
}

int main(){


    return 0;
}