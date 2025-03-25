//Check for Prime Number Method-1 Naive Solution 

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n == 1) 
    return false;

    for(int i = 2;i<n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}


int main(){

    int n;
    cin>>n;
    cout<<"Number is : "<< n <<endl;


    if(isPrime(n) == true)
    cout<<n<<" is Prime Number"<<endl;

    else
    cout<<n<<" is not Prime Number"<<endl;

    return 0;
}