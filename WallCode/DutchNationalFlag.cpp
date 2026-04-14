#include<bits/stdc++.h>
using namespace std;

int dutchNationalFlag(vector<int> &arr){

    int n = arr.size();

    int low = 0, high = n-1, mid = 0;

    while(mid <= high){
        
        if(arr[mid] == 0 )
        {
            swap(arr[low], arr[mid]);
            low++,mid++;
        }

        else if(arr[mid] == 1) mid++;

        else{
            swap(arr[mid] , arr[high]);
            high--;
        }
    
    }
}

int main(){


}