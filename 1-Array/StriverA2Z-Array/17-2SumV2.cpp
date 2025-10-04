#include<iostream>
using namespace std;
//arr[] = {1,2,3,4,5} , target = 6;
//array is sorted and a has one solution.

vector<int> optimal_solution(vector<int> &arr,int target){
    int left = 0,right = arr.size()-1;

    while(left < right) {
        int sum = arr[right] + arr[left];

        if(sum == target)
        return {left , right}; //O-based indexing

        if(sum < target){
            left ++;
        }

        else{
            right -- ;
        }
    }

    return{};

 }

int main(){

    vector<int> arr = {1,2,3,4,5};
    int target = 7;


    cout<<arr.size()<<endl;

    vector<int> ansArr = optimal_solution(arr,target);

    for(auto i : ansArr){
        cout<<i<<" ";
    }

    return 0;
}