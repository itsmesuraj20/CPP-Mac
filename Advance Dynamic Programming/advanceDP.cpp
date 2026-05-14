//Dynamic Programming 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxSum = arr[0];
    int currentSum = arr[0];

    for(int i=1;i<n;i++){
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    cout << "Maximum sum of contiguous subarray: " << maxSum << endl;

    return 0;
}