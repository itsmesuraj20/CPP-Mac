#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3};
    sort(nums.begin(), nums.end());
    do
    {
        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }

    while (next_permutation(nums.begin(), nums.end()));
}