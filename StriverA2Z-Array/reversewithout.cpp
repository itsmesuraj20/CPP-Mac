#include<iostream>
using namespace std;

void reverseManual(int arr[],int n , int start , int end){
    
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp; 

        start++;
        end--;
    }

    for(int i = 0 ; i < n ; i++){
        cout<< arr[i] << " ";
    }

    return ; 
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int s = 0 , e = n-1;
    reverseManual(arr , n,s, e);
    return 0;
}