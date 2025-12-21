#include<iostream>
#include<vector>

/*
Question : Left Rotate an array one place
No Brute
*/

int main(){
    std::vector<int> arr = {1,2,3,4,5};

    int temp = arr[0];

    for(int i = 1; i<arr.size();i++){
        arr[i-1] = arr[i];
    }

    arr[arr.size()- 1] = temp;

    for(int i : arr){
        std::cout<<i<<" ";
    }

    //TC - O(n)
    //SC - O(1)
}