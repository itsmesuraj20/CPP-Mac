#include<bits/stdc++.h>
using namespace std;

vector<int>brute_2Sum(vector<int> &arr , int k) {
    int n = arr.size();
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ;j<n ; j++){
            if(arr[i]+arr[j] == k){ //Yaha galti ki thi 
                return {i,j};
            }
        }
        
    }
    return {-1,-1};
}

void better_() {
    mpp<int> map;

    for(int i=0;i<arr.size();i++)
    {
        map[i] = arr[i];
    }

    for(auto i : map){
        if(map.first)
    }
}

void optimal_() {
    
}

int main(){


    vector<int> arr = {1,2,3};
    int sum  = 5;

    vector<int> arrAns = brute_2Sum(arr, sum);

    for(int i= 0;i<arrAns.size(); i++){
        cout<<arrAns[i]<<" ";
    }

    return 0;
}