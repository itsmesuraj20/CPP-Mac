//Dutch algorithm 


#include<bits/stdc++.h>
using namespace std;
   0          11
1- 2,0,2,1,1, 0
2- 
vector<int> dutchalgo(vector<int> &arr)
{
    int n = arr.size();
    int low = 0 , high = n-1,mid = 0;
    
    while(low < high){
        if(mid == 0){
            swap(arr[low] , arr[mid]);
            low++,mid++;
        }

        else if(mid == 1){
            swap(arr[mid],arr[high]);
            low++,mid--;
        }

        else{
            swap(arr[mid] ,arr[high]);
            high--;
        }
    }
    
}


int main(){


    return 0 ;
}