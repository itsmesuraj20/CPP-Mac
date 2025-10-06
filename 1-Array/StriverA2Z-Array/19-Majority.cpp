//LC - https://leetcode.com/problems/majority-element/description/


// Algorithm used : Moore's Voting Algorithm

#include<bits/stdc++.h>
using namespace std;

void brute_MajorityElement(vector<int> &arr){ // *Revise this 
    
    int n = arr.size();
    int check = n/2;
    int ans = -1 ;
    for(int i = 0 ; i< n ; i++){
        int cnt = 0;
        for(int j = 0; j<n ; j++){
            if(arr[i] == arr[j]){
                cnt++;
            } 
        }
            if(cnt > check) {
                ans = cnt;
            } ;
    }
    if(ans != -1)
    cout<<"Ans : " <<ans <<endl; 
    else
    cout<<"No element available"<<endl;
   
}


void better_MajorityElement(vector<int> &arr){

    int n = arr.size();

    unordered_map<int,int> map;

    for(int i = 0; i < n ; i++){
        map[arr[i]]++;
    }

    for(auto &it : map){
        if(it.second > (n/2)) {
            cout<<it.first<<endl;
            return;
        }
    }
}

int main(){

    // vector<int> arr = {1,2,1,1,2,2,3,1,2,3};
    vector<int> arr = {3,2,3};
   
    cout<<arr.size()<<endl;


    brute_MajorityElement(arr);
    // better_MajorityElement(arr);
    // optimal_MajorityElement(arr);
}