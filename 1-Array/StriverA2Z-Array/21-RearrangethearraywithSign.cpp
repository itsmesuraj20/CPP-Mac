//LC 2149 : https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

/*
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> brute_reArrange(vector<int> &arr){
    int n = arr.size();

    vector<int> posArr;
    vector<int> negArr;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] > 0 ){
            posArr.push_back(arr[i]);
        }
        else{
            negArr.push_back(arr[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[2*i] = posArr[i];
        arr[2*i + 1] = negArr[i];
    }


   return arr;
    
}

// vector<int> optimal_reArrange(vector<int> &arr){

// }


int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};
    vector<int> ans = brute_reArrange(arr);

    for(int i : ans){
        cout<< i <<" " ;
    }

}