#include<bits/stdc++.h>
using namespace std;
bool ls(vector<int> arr, int x){
    int n = arr.size();
    int target = x;
    
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == target){
            return true;
            break;
        }

    }

    return false;
    
}

int brute(vector<int> &arr){
    int n = arr.size();

    int longest = 1 , x ,count;
    for(int i = 0; i < n ; i++){
        x = arr[i];
        count = 1;

        while(ls(arr,x+1) == true){
            x = x+ 1;
            count++;
        }
    }

    return count;
}


int main(){
    vector<int> arr = {104,102,5,4,100,1,101,3,2,1,1};
    
    cout<<brute(arr);

  

    return 0;
}