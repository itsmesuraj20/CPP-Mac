#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vvi vector<vector<int>> 

int smallestBrute(vi &arr)
{
    if(arr.empty()) return INT_MAX; //Handle empty case
    sort(arr.begin(),arr.end());
    return arr[0]; 
    
    //TC - O(n log n)
    //SC - O(1) or O(log n)
}

int smallestOptimal(vi &arr){
    int n = arr.size();

    if(arr.empty()) return INT_MAX;

    int smallest = arr[0];
    for(int i = 1 ; i < n ; i++){
        if(arr[i]< smallest){
            smallest = arr[i];
        }
    }
    return smallest;
}

int main(){
    // vi arr = {9,5,10,4};
    vi arr = {};

    cout<<smallestBrute(arr)<<endl;
    cout<<smallestOptimal(arr)<<endl;
    return 0;
}