#include <bits/stdc++.h>
using namespace std;
void bSearch(vector<int> &arr, int low, int right, int target)
{
    // Base Case
    if (low > right)
    {
        cout << "Not Found" << endl;
        return;
    }

    int mid = low + (right - low) / 2; // This is very important formula must need to take of this

    if (arr[mid] == target)
    {
        cout << "Found" << endl;
        return;
    }

    else if (arr[mid] < target)

        bSearch(arr, mid + 1, right, target);

    else
        bSearch(arr, low, mid - 1, target);
}
int main()
{
    vector<int> arr = {1, 5, 6, 7, 9};
    int target = 9;
    int n = arr.size();
    bSearch(arr, 0, n - 1, target);
    return 0;
}