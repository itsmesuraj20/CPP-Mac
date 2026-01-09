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

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);
    for (int k = 0; k < temp.size(); k++) arr[l + k] = temp[k];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}


int main()
{
    vector<int> arr = {1, 5, 6, 7, 9};
    int target = 9;
    int n = arr.size();
    bSearch(arr, 0, n - 1, target);
    return 0;
} 