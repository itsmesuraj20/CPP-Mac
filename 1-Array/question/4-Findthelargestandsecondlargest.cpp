#include<bits/stdc++.h>
using namespace std;

int largestBruteMethod(vector<int> arr){
    sort(arr.begin(),arr.end());

    return arr.back();

    //TC- O(nlogn) :  Because of Sorting
    //SC - O(1)
}

int secondLargestBruteMethod(vector<int> arr){
    sort(arr.begin(),arr.end());
    int largestSoFar = arr.back();

    for(int i = arr.size()-2;i>=0 ;i--){
        if(arr[i] != largestSoFar){
            return arr[i];

        }
    }

    //TC - O(n)
    //SC- 0(1)
    return -1;
}

int largestBetter(vector<int> arr){
    int largestSoFar = arr[0];
    
    for(int i = 1;i<arr.size();i++){
        if(arr[i] > largestSoFar){
            largestSoFar = arr[i];
        }
    }

    return largestSoFar;

    //TC- O(N)
    //SC- O(1)
}

int secondLargestBetter(vector<int> arr){
    int largestSoFar = largestBetter(arr);

    int secondLargestSoFar = -1;

    for(int i = 0 ; i<arr.size();i++)
    {
           if(arr[i] > secondLargestSoFar && arr[i] != largestSoFar)
            secondLargestSoFar = arr[i];
    }
    return secondLargestSoFar;

    //TC - O(N + N) = O(N)
    //SC - O(1)
}

int largestOptimal(vector<int> arr){

}

int secondLargestOptimal(vector<int> arr){
    int largestSoFar = arr[0];
    
    for(int i = 1;i<arr.size();i++){
        if(arr[i] > largestSoFar){
            largestSoFar = arr[i];
        }
    }
}

int main(){
    // vector<int> arr = {12,11,10};
    vector<int> arr = {1,2,3,4,5};
    // vector<int> arr = {-1,-2,-3};
    // vector<int> arr = {2,2,2};
    // vector<int>arr = {};


    if(arr.empty()){
        cout<<"Array is empty cant proceed"<<endl;
    }
    else{
    cout<<"Brute Method" << endl;
    
    cout<<"Largest in the array : " << largestBruteMethod(arr) << endl;
    cout<<"Second Largest in the array : " << secondLargestBruteMethod(arr) << endl;
    cout<<"\n";
    cout<<"Better Method" << endl;

    cout<<"Largest in the array in the better : " << largestBetter(arr) << endl;
    cout<<"Second Largest in the array better : " << secondLargestBetter(arr) << endl;
    cout<<"\n";
    cout<<"Optimize Method" << endl;

    cout<<"Largest in the array in the optimized " << largestOptimal(arr) << endl;
    cout<<"Second Largest in the array " << secondLargestOptimal(arr) << endl;
    
    }
}