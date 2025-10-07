// LC - https://leetcode.com/problems/maximum-subarray/description/

// Algorithm used :  Kadane Algorithm

/*

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

*/

#include <iostream>
using namespace std;
#define endl "\n"

int brute_MaximumSubArray(vector<int> &arr)
{
    int n = arr.size();

    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int better_MaximumSubArray(vector<int> &arr)
{
    int n = arr.size();

    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}


int optimal_MaximumSubArray(vector<int> &arr)
{
    //Kadane Algorithm 
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if(sum > maxi){
            maxi = sum ;
        }
        if(sum < 0) sum = 0;
    }

    return maxi;
    
}

void unknown(vector<int> &arr){

    //Kadane Algorithm 

    int maxi = INT_MIN;
    int sum = 0;
    int ansStart ,ansEnd, start ;

    for (int i = 0; i < arr.size(); i++)
    {
        if(sum == 0) start = i; //Potential new subarray

        sum += arr[i];

        if(sum > maxi){
            maxi = sum ;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0) 
        sum = 0;

    }

    cout << "Max Sum = " << maxi << endl;
    cout << "Subarray indices: " << ansStart << " to " << ansEnd << endl; 
}


int main()
{

    vector<int> arr = { -2,1,-3,4,-1,2,1,-5,4 };
    // for (int i = 0; i < arr.size(); i++) {
    //     cout << arr[i] << "  ->  " << i << endl;
        
    // }
    // vector<int> arr = {5, 4, -1, 7};

    cout <<"Brute : "<<brute_MaximumSubArray(arr)<<endl;
    cout<<"Better : "<<better_MaximumSubArray(arr)<<endl;
    cout<<"Optimal : "<<optimal_MaximumSubArray(arr)<<endl;
    unknown(arr);

    return 0;
}
