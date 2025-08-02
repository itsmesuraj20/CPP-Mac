#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 

/*
Find the duplicates 
[1,1,2,3,4,5,6,6] , suppose only one duplicate present in the array

From coding Ninjas

*/

int checkBrutev1(vi arr){
    int n = arr.size();
    int ans = -1;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1; j<n ; j++){
            if(arr[i] == arr[j]){
                return ans;
            }
        }
    }
    return -1;
}


// int checkBrutev2(vi arr){
//     int n = arr.size();

//    unordered_map<int,int> mp;
//     for(int i = 0 ; i<n;i++){
//         mp[arr[i]]++;
//     }

//     for(auto  i : mp){
//         if(i.second != 1){
//             return i.first;
//         }
//     }
//     return -1;

//     //TC : O(n);
//     //SC : O(n);

// }

int main(){
    // vi arr = {5,1,2,3,4,4,9,0};
    vi arr = {1,2,3,4,5};

    int ans = checkBrutev1(arr);

    if(ans == -1){
        cout<<"No Duplicate found";
    }
    else{
        cout<<"Duplicate Element is : "<< ans ; 
    }

return 0;

}