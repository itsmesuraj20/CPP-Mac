//M-1's Efficient Solution for Prime Number

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n == 1 ) return false;

    for(int i = 2; i*i <= n ; i++){
        if(n % i == 0 )
        return false;
    }

    return false;

}

int main(){

    int n;
    cout<<"Enter the number "<<endl;
    cin>>n;
    cout<<"Number is : "<<n<<endl;

    if(isPrime(n) == true)
    cout<<"Number is : " << n << "Prime";

    else
    cout<<"Number is : " << n << " not a Prime"<<endl;


    return 0;
}
