#include<bits/stdc++.h>‹
using namespace std;

int maxSumSubArray(int arr[], int n , int k){
    int max_sum = INT_MIN;
    int window_sum = 0;

    for (int i = 0; i < k; i++)
    {
        window_sum += arr[i];
    }
    
    for(int i = k ; i<n;i++){
        window_sum += arr[i] - arr[i-k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}


int main(){
    int arr[] = { 0,-4 ,2, 3,1,6, -4,2, 1,5, 7,6, 7, 8,0, 9,10};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum sum of subarray of size "<<k<<" is "<<maxSumSubArray(arr,n,k);

    return 0;
}