// Rearrange the order without preserving the order of the element dont like previous one


#include<bits/stdc++.h>
using namespace std;

vector<int> SingleSolutionforthisQuestion(vector<int> &arr){

    int n = arr.size();
    
    int left = 0, right = n-1;
    while(left < right){
        while(left < n && arr[left] >  0)
        {
            left++;
        }

        while(right >= 0 && arr[right] < 0){
            right--;
        }

        if(left<right){
            swap(arr[left],arr[right]);
            left++ , right--;
        }
    }

    return arr;
}


int main(){
    vector<int> arr = {3,-2,1,-2,9,6,1};

    vector<int> ans = SingleSolutionforthisQuestion(arr);

    for(int i: ans) cout<<i << " ";
    return 0;
}

