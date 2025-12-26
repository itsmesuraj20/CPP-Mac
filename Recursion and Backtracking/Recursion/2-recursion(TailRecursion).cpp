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
int main(){

    int n ;
    cin>> n ; 

    cout<<"Factorial : " << factorial(n) << endl;
    int sum = 0;
    cout<<"Sum : " << summ(n , sum)<< endl;
    return 0;
}