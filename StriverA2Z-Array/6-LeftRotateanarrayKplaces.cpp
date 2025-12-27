#include<iostream>
#include<vector>
#define vi vector<int> 
//Only Brute and Optimal Exist , no better
using namespace std;

vector<int> bruteRotate(vector<int> arr ,int d ){
   //SC - O(n)
    vector<int> temp; //Same in Rotating by one place , there we were storing one element because we are required to do one place rotation,and here we are required to rotate K element
    if(arr.empty()) return arr;
    
    int n = arr.size();
    d = d % n ;

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

   //TC = O(d) + O(n) + O(n-d)
   //TC = O(d + n + n - d )


   //TC = O(n+d);
   //SC = O(d); 
}

vi optimal(vi arr , int d){
    int n = arr.size();

    d = d % n ;
    //Formula which can take to reduce the complexity

    reverse(arr.begin(),arr.begin() + d); //
    reverse(arr.begin() + d , arr.end());
    reverse(arr.begin(), arr.end());

    return arr;
    //TC = O(n);
    //SC = O(1); // As we havent use any extra space 
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,0};
    int d = 326;

    vector<int> newArr = bruteRotate(arr,d);
    vector<int> newArr2 = optimal(arr,d);

    for(int i : newArr){
        cout<<i<<" ";
    }
    cout<<endl;

    for(int i : newArr2){
        cout<<i<<" ";
    }
    
    return 0;
}