#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {1,1,0,1,1,1,1,0,1,1};

    int c = 0, maxVal = 0;
    for(int i=0 ; i< arr.size();i++){
        if(arr[i] == 1){
            c++;
            maxVal = max(maxVal,c);
        }
        else { 
            c = 0;
        }
    }

    cout<<"Maximum is : " << maxVal;
    return 0;
}