//Leader of the array say that the element which is greatest among its right side .

#include<bits/stdc++.h>
using namespace std;

vector<int> brute (vector<int> &arr ,vector<int> &result){
    int n = arr.size();
    for(int i = 0 ;i < n ; i++ ){
        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i] < arr[j]){
                leader = false;
                break;
            }
        }
        if(leader == true){
            result.push_back(arr[i]);
        }
    }

    return result;
}

vector<int> optimal(vector<int> &arr,vector<int> &result2){
    int n = arr.size();
    // vector<int> result2;
    int maxSoFar = INT_MIN;
    for(int i = n-1;i>=0 ;i--){
        if(arr[i] > maxSoFar){
            result2.push_back(arr[i]);
            maxSoFar = arr[i];
        }
    }

    return result2;
}

int main(){
    vector<int> arr = {10,22,12,3,0,6};
    // vector<int> arr = {0 , 0 ,0 , 0 ,0};
    // vector<int> arr = {};
    // vector<int> arr = {1,2,3,4,5};
    // vector<int> arr = {5,4,3,2,1};
    // vector<int> arr = {-1,-2,-3,-4,-5};

    vector<int> result2;
    // brute(arr,result);
    //No better availble for this
    optimal(arr , result2);
    

    for(int x : result2){
        cout<<x<<" ";
    }


    return 0;
}