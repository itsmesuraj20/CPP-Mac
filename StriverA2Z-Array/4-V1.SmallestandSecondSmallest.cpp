#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

int smallestBrute(vi &arr)
{
    if (arr.empty())
        return INT_MAX; // Handle empty case
    sort(arr.begin(), arr.end());
    return arr[0];

    // TC - O(n log n)
    // SC - O(1) or O(log n)
}

int smallestOptimal(vi &arr)
{
    int n = arr.size();

    if (arr.empty())
        return INT_MAX;

    int smallest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    return smallest;
}

int secondSmallestBrute(vi &arr)
{
    int n = arr.size();
    if (n < 2)
        return INT_MAX;

    sort(arr.begin(), arr.end()); // O(n log n);

    int smallest = arr[0]; // for sure hai ki yahi hai

    for (int i = 1; i < n; i++)
    {
        // 5 > 4
        if (arr[i] > smallest)
        {
            return arr[i];
        }
    }
}

int secondSmallestBetter(vi &arr){
    int n = arr.size();
    if (n < 2)
        return INT_MAX;

    int smallest = smallestOptimal(arr);

    int secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] > smallest && arr[i] < secondSmallest){
            secondSmallest = arr[i];
        } 
    }

    return secondSmallest;
    
}

int secondSmallestOptimal(vi &arr){
    int n = arr.size();
    if(n < 2) return INT_MAX;


    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    
}

int main()
{
    vi arr = {9, 5, 10, 4};
    // vi arr = {};

    // cout << smallestBrute(arr) << endl;
    // cout << smallestOptimal(arr) << endl;
    // cout << secondSmallestBrute(arr) << endl;
    cout << secondSmallestBetter(arr) << endl;
    return 0;
}