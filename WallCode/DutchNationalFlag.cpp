#include<bits/stdc++.h>
using namespace std;

vector<int> dutchNationalFlag(vector<int> &arr){

    int n = arr.size();

    int low = 0, high = n-1, mid = 0;

    while(mid <= high){
        
        if(arr[mid] == 0 )
        {
            swap(arr[low], arr[mid]);
            low++,mid++;
        }

        else if(arr[mid] == 1) mid++;

        else{
            swap(arr[mid] , arr[high]);
            high--;
        }
    
    }
    return arr;
}

int main(){

    vector<int> arr = {2,1,0,1,0,1,2,1,1,0};

    vector<int> ans = dutchNationalFlag(arr);

    for(int i : ans){
        cout<< i << " "; 
    }


    return 0;
}