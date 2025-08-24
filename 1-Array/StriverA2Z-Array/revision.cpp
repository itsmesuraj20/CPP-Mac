#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {0,1,3,0,12};

        vector<int> arr;
        int n = nums.size();
        int countZero = 0;
        cout<<n<<endl;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != 0){
                arr.push_back(nums[i]);
            }
            else{
                countZero++;
            }
        }

        
        cout<<"New N : "<< n <<endl;
        while(countZero--){
            arr.push_back(0);
        }

       
        
}


// int main(){
//     vector<int> arr = {1,2,3,4,5};

//     // .erase function is used to delete the position index value from vector array
//     arr.erase(arr.begin() + ); // Erase element at index 4 (i.e., value 5)

//     for(int i : arr){
//         cout << i << " ";
//     }

//     return 0;
// }

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