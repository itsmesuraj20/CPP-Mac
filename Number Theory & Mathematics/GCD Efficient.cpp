#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    //GCD Efficient Solution
    int a,b;
    cin>>a>>b;

    cout<<"GCD is : "<<gcd(a,b)<<endl;

}
//TC : O(log(min(a,b)))