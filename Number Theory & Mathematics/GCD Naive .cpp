
#include<bits/stdc++.h>
using namespace std;

int main(){
    //GCD Naive Solution
    int a,b;
    cin>>a>>b;

    int res = min(a,b);

    while(res > 0){
        if(a % res == 0 && b % res == 0){
            break;
        }
        res--;
    }

    cout<<"GCD is : "<<res<<endl;

}

//TC : O(min(a,b))
//SC : O(1)