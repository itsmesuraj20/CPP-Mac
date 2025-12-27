#include<iostream>
#include<vector>
// #define vi vector<int> 

using namespace std;

vector<int> bruteRotate(vector<int> &arr ,int d ){
   
    vector<int> temp; //Same in Rotating by one place , there we were storing one element because we are required to do one place rotation,and here we are required to rotate K element

    int n = arr.size();

    for(int j = 0;j<d;j++){
        temp.push_back(arr[j]);
    }

    for(int i = d;i < n;i++){
        arr[i-d] = arr[i];
    }
 
   for(int a = n - d; a < n ; a++){
    arr[a] = temp[a-(n - d)];
   }

   return arr;
}

vi better(vi &arr , int d){
    int n = arr.size();

    // d = d % n ;
    //Formula which can take to reduce the complexity
    
}

vi optimal(vi &arr, int d)

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,0};
    int d = 4;

    // vector<int> newArr = bruteRotate(arr,d);
    vector<int> newArr2 = optimalRotate(arr,d);

    for(int i : newArr2){
        cout<<i<<" ";
    }
    return 0;
}