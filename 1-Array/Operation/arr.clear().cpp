#include <bits/stdc++.h>
using namespace std;

// arr.clear() - works on vector array not on static array.
// memset(arr, 0, sizeof(arr)); // sets all elements to 0 in the normal array./

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n;


    memset(arr, 0, sizeof(arr)); // sets all elements to 0

     int m = sizeof(arr) / sizeof(arr[0]);
    cout<<m;
    return 0;
}


int arr[] = {1, 2, 3};
memset(arr, 0, sizeof(arr)); // sets all elements to 0
