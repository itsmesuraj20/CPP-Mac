#include<bits/stdc++.h>
using namespace std;

// ============================================================================
// PATTERN 1: LINEAR RECURSION (Most Common) [Easy to understand]
// ============================================================================

void print1toN(int n ) { 
//Basically what happens is 
    /*
     n = 2

     print(2) , waiting for cout statement exec. because of stack 
        ----> print(1) , same for this 
                ------> print(0) -> return statement exec 
                cout<<1<<endl;
                then , cout<<2<<endl;


    Final Output -> 1
                    2

    
    */
    if(n <= 0)
        return ;

    print1toN(n-1);
    cout<<n<<" ";

    
}


void printNto1(int n){
    if(n == 0)
    return ;


    cout<<n<<" ";
    printNto1(n-1);
}


int  sumofN(int n ){
    if(n == 0) return 0;

    return n + sumofN(n-1);
}


int powN( int x , int n)
{
    if(n == 0) return 1;

    return x*powN(x,n-1);
}

int countDigits(int n){
    if( n == 0 )return 0;

    abs(n);
    if(n/10 == 0) return 1;

    return 1+countDigits(n/10);
}
int main(){
   
    int n;
    cin>>n;

    int x = 5;

    print1toN(n);
    cout<<endl;

    printNto1(n);
    cout<<endl;

    int sum = sumofN(n);
    cout<<"Sum : " << sum << endl;

    
    int power = powN(x,n );
    cout<<"Power : " << power<<endl;

    int longNum = 900;
    int count = countDigits(longNum);
    cout<<"Count : "<<count<<endl;

    return 0;
}