#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,2,3,4,5};

    // .erase function is used to delete the position index value from vector array
    arr.erase(arr.begin() + ); // Erase element at index 4 (i.e., value 5)

    for(int i : arr){
        cout << i << " ";
    }

    return 0;
}

// int main(){
//     //  vector<int> arr = {1,2,3,4,5,6,7,8,9,0};
//      vector<int> arr = {1,2,3,4,5};
//     int d = 2;

//     vector<int> temp;
//     int n = arr.size();
//     int end = n-d;
//     for(int i = 0;i<end;i++){
//         temp.push_back(arr[i]);
//     }

//     int j = 0;
//     for(int i = 0 ;i<n;i++){
//        arr[j] = arr[i];
//         j++;
//     }

//     for(int i : arr){
//         cout<<i<<" ";
//     }

//     return 0;
// }