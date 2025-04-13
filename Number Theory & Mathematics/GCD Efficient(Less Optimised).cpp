//GCD Efficient also know as Euclidean algorithm

/*

:- Basic Idea 
let 'b' be the smaller than 'a'
gcd(a,b) = gcd(a-b,b)

Why? -
Let 'g' be GCD of 'a' and 'b'
a=gx ,b=gy and GCD (x,y) = 1
(a-b) =g(x,y)

*/


//Naive Method of Efficient Solution

#include<iostream>
using namespace std;

int gcd(int a, int b){
    while(a!=b)
    {
        if(a>b)
        a = a-b;

        else
        b = b-a;
    }
    return a;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<"Numbers are : " <<a<<" , "<<b<<endl;

    int sol = gcd(a,b);
    cout<<sol;

    return 0;
}