#include<iostream>
#include<map>
using namespace std;

/*
Find the missing number in an array;
arr [] = {3,0,1}
ans = 2;

arr[] = {0,1,2,4,5}
ans = 3

*/

void brute_missingnum(vector<int> &arr)
{

    sort(arr.begin() , arr.end());
    int n = arr.size();

    for(int i = 1 ; i < n ; i++ ) // 0 1 2 3 4
    {
        int flag = 0;
        for (int j = 0; j < n-1; j++) // 0 1 2 4
        {
            if(arr[j] == i ){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<< i << endl;
        }
    }
}


void better_missingnum(vector<int> &arr){
    map<int,int> hashmap;
    int n = arr.size();
    hashmap[n+1] = 0;

    for(int i = 0 ; i< n ; i++){
        hashmap[arr[i]] = 1;
    }

    for(int i = 1 ; i< n;i++){
        if(hashmap[i] == 0){
            cout<< i <<"\n";
        }
    }
}

void optimal_missingnum(vector<int> &arr){

    int n = arr.size();
    int totalSum = (n * (n+1))/2;

    int s2{0};

    for(int i = 0;i < n;i++){
        s2 += arr[i];
    }

    cout<<(totalSum - s2)<<endl;

}

void optimal_missingnum2(vector<int> &arr){
    //Using two loop
    //TC - O(2N) , SC=O(1);
    int XOR1 = 0;
    int n = arr.size();

    for(int i = 1; i<n;i++){
        XOR1 = XOR1^i;
    }
    int XOR2=0;

    for(int j = 0; j<n-1;j++){
        XOR2 = XOR2 ^ arr[j];
    }

    int  ans =  (XOR1 ^ XOR2);
    cout<<ans;

}

void optimal_missingnum3(vector<int> &arr){
    //Reduced to one loop
    //TC - O(n) , SC=O(1);
    int n = arr.size() + 1;  // because 1 number is missing
    int xorAll = 0;

    for (int i = 0; i < n - 1; i++) {
        xorAll ^= arr[i];      // XOR with array element
        xorAll ^= (i + 1);     // XOR with 1..n-1
    }

    xorAll ^= n;  // finally XOR with n
    cout << xorAll;

}

int main(){

    // vector<int> arr = {0,1,2,4,5};
    vector<int> arr = {3,0,1};
    // vector<int> arr = {0,2,3,4,5};

    brute_missingnum(arr);
    better_missingnum(arr);
    optimal_missingnum(arr);
    optimal_missingnum2(arr);

    return 0;
}