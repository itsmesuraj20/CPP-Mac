#include<bits/stdc++.h>
using namespace std;

int largestBruteMethod(vector<int> &arr){
    sort(arr.begin(),arr.end());

    return arr.back();

    //TC- O(nlogn) :  Because of Sorting
    //SC - O(1)
}

int secondLargestBruteMethod(vector<int> &arr){
    int largestSoFar = largestBruteMethod(arr);
    for(int i = arr.size()-2;i>=0 ;i--){
        if(arr[i] != arr[arr.size()-1]){
            return arr[i];

        }
    }

    //TC - O(n)
    //SC- 0(1)
    return -1;
}

int largestBetter(vector<int> arr){
    int largestSoFar = arr[0];
    return 0;
}

int secondLargestBetter(vector<int> arr){

    return 0;
}

int largestOptimal(vector<int> arr){

    return 0;
}

int secondLargestOptimal(vector<int> arr){

}

int main(){
    vector<int> arr = {1,2,3};

    cout<<"Brute Method" << endl;
    
    cout<<"Largest in the array : " << largestBruteMethod(arr) << endl;
    cout<<"Second Smallest in the array : " << secondLargestBruteMethod(arr) << endl;

    cout<<"Better Method" << endl;

    cout<<"Largest in the array in the better " << largestBetter(arr) << endl;
    cout<<"Second Smallest in the array better " << secondLargestBetter(arr) << endl;

    cout<<"Optimize Method" << endl;

    cout<<"Largest in the array in the optimized " << largestOptimal(arr) << endl;
    cout<<"Second Smallest in the array " << secondLargestOptimal(arr) << endl;


}