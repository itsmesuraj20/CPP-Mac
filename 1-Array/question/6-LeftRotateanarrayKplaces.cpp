#include<iostream>
#include<vector>
// #define vi vector<int> 

using namespace std;

vector<int> bruteRotate(vector<int> arr ,int d ){
    vector<int> temp;
    for(int j = 0;j<d;j++){
        temp.push_back(arr[j]);
    }

    for(int i = d;i<arr.size();i++){
        arr[i-d] = arr[i];
    }
    int j=0;
   for(int a = arr.size() - d;a<arr.size(); a++){
    arr[a] = temp[j];
    j++;
   }

   return arr;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,0};
    int d = 4;

    vector<int> newArr = bruteRotate(arr,d);

    for(int i : newArr){
        cout<<i<<" ";
    }
    return 0;
}