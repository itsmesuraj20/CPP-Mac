#include<bits/stdc++.h>
using namespace std;

void print1toN(int n ) { 
    
    if(n <= 0)
        return ;

    print1toN(n-1);
    cout<< n << endl;

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
}

int main(){
   
    int n ;
    cin>>n;

    print1toN(n);
    return 0;
}