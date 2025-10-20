#include<bits/stdc++.h>
using namespace std;

vector<int>brute_2Sum(vector<int> &arr , int k) {
// O(N2)

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

vector<int>optimal_2Sum(vector<int> &arr,int k) {
   unordered_map<int,int> map ;
   int n = arr.size();
   for(int i = 0 ; i < n ; i++ ){
    int complement =  k - arr[i];

    if(map.find(complement) != map.end()){
        return {map[complement] , i};
    }
    map[arr[i]] = i;


   }
   return {};

}


int main(){


    vector<int> arr = {1,2,3};
    int sum  = 5;

    // vector<int> arrAns = brute_2Sum(arr, sum);
    vector<int> arrAns = optimal_2Sum(arr, sum);

    for(int i= 0;i<arrAns.size(); i++){
        cout<<arrAns[i]<<" ";
    }

    return 0;
}