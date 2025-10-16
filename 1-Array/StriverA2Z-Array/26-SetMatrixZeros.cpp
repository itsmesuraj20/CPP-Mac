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

void markRow(vector<int>> &arr, int i ,int m ){
    for (int i = 0; i < m; i++)
    {
        if(arr[i][j] != 0){
            curr[i][j] = -1; // Marking , not zero immediately.
        }
    }
}

markCol(vector<int>> &arr, int j , int n){
    for (int i = 0; i < n; i++)
    {
        if(arr[i][j] != 0)
        arr[i][j] = -1; // Marking , not zero immediately.
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
                markRow(i);
                markCol(j);
            }
        }    
    }

    for()


}

int main(){
    brute();
    return 0;
}