//LC - https://leetcode.com/problems/maximum-subarray/description/

//Algorithm used :  Kadane Algorithm

/*

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

*/

#include<iostream>
using namespace std;
#define endl "\n"

int brute_MaximumSubArray(vector<int> &arr){
    int n = arr.size();

    int maxi = INT_MIN;
    for(int i = 0; i< n ; i++){
        for(int j = 0; j<n ;j++){
            int sum = 0 ;
            for (int k = i; k <= j ; k++)
            {
                sum += arr[k];
            }
            maxi = max(maxi,sum);
        }
    }

    return maxi;
}

int better_MaximumSubArray(vector<int> &arr){

}

int optimal_MaximumSubArray(vector<int> &arr){

}


int main(){

    // vector<int> arr = { -2,1,-3,4,-1,2,1,-5,4 };
    vector<int> arr = {5,4,-1,7,8};

    cout<<brute_MaximumSubArray(arr);
    // cout<<better_MaximumSubArray(arr);
    // cout<<optimal_MaximumSubArray(arr);

    return 0;
}
