#include<bits/stdc++.h>
using namespace std;

//RotateArrayto 90 Degree.
void brute(vector<vector<int>> &arr , int n){

    vector<vector<int>> ans(n,vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //Formula i -> (n-1)-i
            ans[j][n-1-i] = arr[i][j];
        }    
    }
    //TC and SC -> O(N*N) and O(N*N);

    cout<<"After"<<endl;
    for(int i = 0;i<n;i++){
        for(int j= 0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}


void optimal_inplace(vector<vector<int>> &arr ,int n ){
    //Transpose in place
     for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
    //Reversing the array
    for(int i = 0; i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }

    cout<<"After"<<endl;
    for(int i = 0;i<n;i++){
        for(int j= 0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> arr = {{1,2,3} ,{4,5,6},{7,8,9}};

    int n = 3;
    cout<<"Before" << endl;

      for(int i = 0;i<n;i++){
        for(int j= 0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


    brute(arr , n);
    optimal_inplace(arr ,n);
   
    return 0;

}