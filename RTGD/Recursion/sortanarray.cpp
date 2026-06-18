#include<bits/stdc++.h>
using namespace std;

void insertElement(vector<int> &arr , int temp){
    int n = arr.size();

    if(n == 0 || arr[n-1] <= temp){
        arr.push_back(temp);
        return ;
    }

    int val = arr[n-1];
    arr.pop_back();

    insertElement(arr,temp);

    arr.push_back(val);
}

void sortArray(vector<int> &arr)
{
    int n = arr.size();
    if(n == 1)
    return ;

    int temp = arr[n-1];
    arr.pop_back();

    sortArray(arr);

    insertElement(arr,temp);
}


int main(){
    vector<int> arr = {1,5,0,2};

    sortArray(arr);

    for(int i : arr){
        cout<< i << " ";
    }
    return 0;
}