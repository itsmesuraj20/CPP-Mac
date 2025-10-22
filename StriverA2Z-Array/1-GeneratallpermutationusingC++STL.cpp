#include <bits/stdc++.h>
using namespace std;
✅
int main()
{
    vector<int> nums = {1, 2, 3};

    //Sort the array
    sort(nums.begin(), nums.end()); // OR sort(arr , arr + n);

    //Do While Loop for each element in the array 
    do
    {
        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }//next_permutation(arr);
    while (next_permutation(nums.begin(), nums.end()));

}