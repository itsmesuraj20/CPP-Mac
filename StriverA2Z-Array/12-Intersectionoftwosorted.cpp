#include<iostream>
using namespace std;
/*
Find the intersection of the two sorted array 

arr1[] = {1,2,2,3,4,5}
arr2[] = {2,2,3,4}

ans_Array [] = {2,2,3,4};


*/


void intersection_brute(vector<int> arr1,vector<int> arr2)
{
    vector<int> ans;
    
    int m = arr1.size(); 
    int n = arr2.size();

   vector<int> vis(n,0);

   for (int i = 0; i < m; i++)
   {
    for(int j = 0 ; j<n ; j++){
        if(arr1[i] == arr2[j] && vis[j] == 0){
            ans.push_back(arr1[i]);
            vis[j] = 1;
            break;
        }
        if(arr2[j] > arr1[i]) break;
    }
   }
   
   for(int i : ans){
    cout<<i<<" ";
   }

}

void intersection_Optimal(vector<int> arr1, vector<int> arr2)
{
    int m = arr1.size();
    int n = arr2.size();

    vector<int> result;

    int i = 0 , j = 0 ; 
    while(i< m && j<n){
    if(arr1[i] > arr2[j]) j++;

    else if(arr1[i] < arr2[j]) i++;

    else
       {
            result.push_back(arr1[i]);
            i++;
            j++;
        }
   }

    for(int i : result){
        cout<<i<< " " ;
    }
}

int main(){
    // vector<int> arr1 = {1,2,2,3,4,5,6}; 
    // vector<int> arr2 = {1,2,2,3,4,7,8};

    vector<int> arr1 = { 1,2,2,3,4};
    vector<int> arr2 = {2,2,3,4};

    // intersection_brute(arr1,arr2);
    intersection_Optimal(arr1,arr2);

    return 0;
}