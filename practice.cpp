#include<bits/stdc++.h>
using namespace std;

vector<int> dutchalgorithm(vector<int> &arr){
    int n = arr.size();

    int low = 0 , mid = 0 , high = n-1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid] , arr[low]);
            low ++;
            high ++;
        }

        else if(arr[mid] == 1){
            mid++;
        }

        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    return arr;
    
}

int main(){
    vector<int> arr ={2,1,0,1,2,0,0,1};

    vector<int> ans = dutchalgorithm(arr);

    for(int i : ans ){
        cout<< i << " ";
    }
    return 0 ;
}