#include<bits/stdc++.h>
using namespace std;
//Dutch National Flag Algorithm
int main()
{
    vector<int> arr = {1,2,0,1,2,0,2,2,1,1,0};

    int n = arr.size();

    int low = 0, high = n-1, mid = 0;

    while (mid <= high)
    {
        if(arr[mid] == 0){
            swap(arr[low] ,arr[mid]);
            low++,mid++;
        }
    
    
    else if (arr[mid] == 1) mid++;
    else {
        swap(arr[mid] , arr[high]);
        high--;
    }
}
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " " ; 
    }
    
    return 0;
}