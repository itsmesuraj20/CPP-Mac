#include<bits/stdc++.h>
using namespace std;

int factorial( int n){
    if( n<= 1) return 1;

    return n*factorial(n-1);
}

int summ(int n ,int sum = 0 ){ // Yaha function ke andar sum = 0 bohot important ,kyunki function ke andar likha to wo baar baar sum ko 0 kar dega

    if(n == 0) return sum;

    return summ(n-1,sum + n);
}

int fib(int n){
    if(n <= 1) return n;

    return fib(n-1) + fib(n-2);
}

int towerOfHanoi(int n , int s, int d , int h){
    if(n == 0) return 0;
    if(n == 1) return 1;

    int x = towerOfHanoi(n-1 ,s,d,h );
    int y = towerOfHanoi(n-1,h,d,s);

    return x+y+1;


    //Here why x+y+1 : To move n disks, you must first move n−1 disks to the helper, then move the largest disk once, and finally move the n−1 disks to the destination. The two recursive calls count the moves for the subproblems, and the +1 accounts for the single mandatory move of the largest disk.
}
int main(){
    //  int n ;
    // cin>> n ; 
    // cout<<"Factorial : " << factorial(n) << endl;
    // int sum = 0;
    // cout<<"Sum : " << summ(n , sum)<< endl;

    int n ;
    cin>> n ; 

    int source,destination,helper;
    source = 1 , destination = 3, helper = 2;

    cout<< "Total Moves : " << towerOfHanoi(n,source,destination,helper) ; 
    return 0;
}