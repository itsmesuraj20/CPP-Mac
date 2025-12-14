//LC : https://leetcode.com/problems/sort-colors/
//Algorithm : Dutch National Flag Algorithm 


//
// O(1) < O(log N) < O(N) < O(N logN) < O(N2) < O(2^N) < O(N!)

/*

Sort the 0' 1' and 2's in the array

KeyNote: Dutch National Flag Algorithm


*/

#include <bits/stdc++.h>
using namespace std;

void bruteMethod(vector<int> &arr)
{

    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout<<endl;
    // Time Complexity: O(n log n)
    // Space Complexity: O(log n)
}

void betterMethod(vector<int> &arr)
{
    int n = arr.size();

    int count0s = 0, count1s = 0, count2s = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0s++;

        if (arr[i] == 1)
            count1s++;

        if (arr[i] == 2)
            count2s++;
    }

    cout << " 0 : " << count0s << endl;
    cout << " 1 : " << count1s << endl;
    cout << " 2 : " << count2s << endl;
    
    int c = 0;
    for (int i = 0; i < count0s ; i++)
    {
        arr[c] = 0; c++;
    }

    for(int i = 0 ; i <  count1s ; i++){
        arr[c] = 1; c++;
    }

    for(int k = 0 ; k < count2s ; k++){
        arr[c] = 2; c++;
    }

    for(auto i : arr){

        cout<< i <<" ";
        
    }

    cout<<"\n";

    // Time Complexity: O(4N)
    // Space Complexity: O(1)
}

void optimalMethod(vector<int> &arr)
{
    //Dutch National Flag Algorithm 
    
    int n = arr.size();

    int low = 0, high = n-1, mid = 0;
    
    while(mid <= high)
    {
        if(arr[mid] == 0) {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }

        else if(arr[mid] == 1) mid++;

        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }


    for(auto i : arr){
        cout<< i <<" ";
    }

    cout<<"\n";
    
}

int main()
{

    vector<int> arr = {1, 0, 2, 0, 1, 2, 0, 2, 1, 0, 0, 1, 1, 2, 0, 1, 1, 1, 0, 2, 1};
    // vector<int> arr = {2,0,1};
    // vector<int> arr = { 1,1,2,0,0,1,2};
    //  vector<int> arr = { 2,0,1,1};


    // bruteMethod(arr);
    betterMethod(arr);
    // optimalMethod(arr);

    return 0;
}