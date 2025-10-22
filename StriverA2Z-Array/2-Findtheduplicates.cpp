#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 

/*
Find the duplicates 
[1,1,2,3,4,5,6,6] , suppose only one duplicate present in the array

From coding Ninjas

*/


/*

Quick Revision -

Brute : 
Do Loop chlao , jisme first wala i->0 se n tak , then j->i+1 se n tak chlega , agar arr[i] == arr[j]
ans = -1; // default pe rahega
howa to return ans; kar dena , nhi to return -1;
TC - O(n^2)
SC - O(1);

Brute (version 2): 
Mein unordered map bnao , usmein jo element ka count 2+ ho wo return krdo simple.



*/


int brute(vi arr){
    int n = arr.size();
    // int ans = -1;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1; j<n ; j++){
            if(arr[i] == arr[j]){
                return arr[i];
            }
        }
    }
    return -1;
}


int optimal(vi arr){
    int n = arr.size();

   unordered_map<int,int> mp;
    for(int i = 0 ; i<n;i++){
        mp[arr[i]]++;
    }

    for(auto  i : mp){
        if(i.second != 1){
            return i.first;
        }
    }
    return -1;

    //TC : O(n);
    //SC : O(n);

}

int main(){
    // vi arr = {5,1,2,3,4,4,9,0};
    vi arr = {2,3,4,5,6,6};
    // vi arr = {1,2,3,4,5};

    int ans = brute(arr);
    // int ans = optimal(arr);
    
    if(ans == -1){
        cout<<"No Duplicate found";
    }
    else{
        cout<<"Duplicate Element is : "<< ans ; 
    }

    return 0;
}