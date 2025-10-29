#include<iostream>
using namespace std;
void brute(vector<int> &arr ,int target){
    
    int c = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for(int j = i ; j < n ;j++){
            int sum = 0;
            for(int k = i ;k <= j ;k++){
                sum += arr[k];
            }
            if(sum == target) c++;
        }
    }

    cout<<c<<endl;
}

void better(vector<int> &arr ,int target){
    
    int c = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i ; j < n ;j++){

                sum += arr[j];

                if(sum == target) c++;
            }
    }

    cout<<c<<endl;

    //TC- O(N*N)
    //SC- O(1)
    
}




int main(){
    // vector<int> arr = {1,2,3,4,5,-6,-7,1,-2,-3,0,9,-8,6,7,4};
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;

    brute(arr,k);
    better(arr,k);
   

    return 0;
}