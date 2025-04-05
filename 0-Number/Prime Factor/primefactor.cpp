#include<iostream>
using namespace std;

void primeFactor(int n){
    for(int i = 2; i < n ; i++ ){
        if(isPrime(i)){
            int x = i;
            while(n % x == 0){
                cout<<i<<endl;
                x = x * i;
            }
        }
    }
}

int main(){
    int n ;
    cout<<"Enter the value : "<<endl;
    cin>>n;
    cout<<n<<" : enter by you " <<endl;

    primeFactor(n);


    
}