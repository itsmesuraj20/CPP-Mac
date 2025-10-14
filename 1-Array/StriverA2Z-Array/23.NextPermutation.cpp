#include<bits/stdc++.h>
using namespace std;

void generatePermutation(int index , vector<int> &arr , vector<vector<int>> &result){
    int n = arr.size();

    if(index == n){
        result.push_back(arr);
        return;
    }


    for(int i = index ; i < n ; i++ ){
        swap(arr[index], arr[i]);
        generatePermutation(index + 1, arr,result);
        swap(arr[index], arr[i]);//Backtrack
    }
}

void brute(int index, vector<int> &arr , vector<vector<int>> result ){

    generatePermutation(index , arr ,result);
    sort(result.begin() , result.end());

    int size = result.size();
    vector<int> target = arr;
    vector<int> ansArr ;
    for(int i = 0 ; i < size ; i++){
        if(result[i] == target){
            if(i + 1 < size){
                ansArr = result[i+1];
            }
            else { 
                ansArr = result[0];
            }


            for(int x : ansArr){
                cout<<x<<" ";
            }
            cout<<endl;

            break;
        }
    }
}


void better(vector<int> &arr)
{
    next_permutation(arr.begin(), arr.end());

    for(int x : arr){
        cout<<x<<" ";
    }

}



int main(){

    vector<int> arr = {3,2,1};
    int index = 0;
    vector<vector<int>> result;

    

    brute(index, arr,result);
    better(arr);
    // optimal();
    return 0;
}