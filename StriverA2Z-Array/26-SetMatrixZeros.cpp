#include<iostream>
using namespace std;

/*
Question : Set Matrix Zero


Static 2D 

Row & Column: 

rows = sizeof(arr) / sizeof(arr[0]);
cols = sizeof(arr[0]) / sizeof(arr[0][0]);

Vector 2D 

int rows = arr.size();
int cols = arr[0].size();
ˀ
*/

void markRow(vector<vector<int>> &arr, int row,int m ){
    for (int i = 0; i < m; i++)
    {
        if(arr[row][j] != 0){
            arr[row][j] = -1; // Marking , not zero immediately.
        }
    }
}

markCol(vector<vector<int>> &arr, int cols , int n){
    for (int i = 0; i < n; i++)
    {
        if(arr[i][col] != 0)
        arr[i][col] = -1; // Marking , not zero immediately.
    }
    
}

void brute(vector<vector<int>> &arr){
    int m = arr.size();
    int n = arr[0].size();
    
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] == 0){
                markRow(arr, i, n);
                markCol(arr, j, m);
            }
        }    
    }

    for(int i = 0;i < m; i++){
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }   
    }
}

void printMatrix(vector<vector<int>> &arr){
    for(auto &row : arr){
        for(int val : arr){
            cout<< val << " ";
        }
        cout<<endl;
    }
}

int main()
{
    
    vector<vector<int>> arr = {{1, 2, 3},{4, 0, 6},{7, 8, 9}};

    cout<<"Original Matrix: \n";
    printMatrix(arr);

    brute(arr);
    
    cout<<"\n After Set Matrix Zero (Brute) : \n";
    printMatrix(arr);

    return 0;
}