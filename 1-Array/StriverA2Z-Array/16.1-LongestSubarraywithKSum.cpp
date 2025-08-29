#include<bits/stdc++.h>
using namespace std;

void longestSubArrayBruteMethod(vector<int> &arr , int K){

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
             int s = 0;
             for (int k = 0; k < j; k++)
             {
                
                s += arr[k];
        
             }

             cout<<s<<endl;
        }
    }
}

int main(){

    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    int k = 3;

    longestSubArrayBruteMethod(arr,k);

    return 0; 
}