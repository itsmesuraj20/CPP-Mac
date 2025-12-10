#include<iostream>
using namespace std;

/*
Question : Set Matrix Zero
3 Solution Exist for this question

Static 2D 

Row & Column: 

rows = sizeof(arr) / sizeof(arr[0]);
cols = sizeof(arr[0]) / sizeof(arr[0][0]);

Vector 2D 

int rows = arr.size();
int cols = arr[0].size();
ˀ
*/
// void markRow(vector<vector<int>> &arr, int row,int m ){
//     for (int j = 0; j < m; j++)
//     {
//         if(arr[row][j] != 0){
//             arr[row][j] = -1; // Marking , not zero immediately.
//         }
//     }
// }

// void markCol(vector<vector<int>> &arr, int col , int n){
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i][col] != 0)
//         arr[i][col] = -1; // Marking , not zero immediately.
//     }
// }


void optimal(vector<vector<int>> &arr){
    
    //V.V.V.V.V. Important isko 2-3 baar

    int m = arr.size();
    int n = arr[0].size();

    int firstRowZero = 0,firstColZero = 0;

    //Step-1 :Check the first row and col
    for (int j = 0; j < n; j++)
    {
        if(arr[0][j] == 0)
           firstRowZero = 1;
    }

    for (int i = 0; i < m; i++)
    {
        if(arr[i][0] == 0)
            firstColZero = 1;
    }
    
    //Step-2 :use first row and col as markers
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(arr[i][j] == 0){
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }
    //Step-3 :use set zero based on markers
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
            }
        }
    }

    //Step-4 :handle first row and col
    if(firstRowZero == 1){ //Row
        for (int j = 0; j < n; j++)
        {
            arr[0][j] = 0;
        }
    }

     if(firstColZero == 1){
        for (int i = 0; i < m; i++)
        {
            arr[i][0] = 0;
        }
    }


    //Step-5 :Output
    cout<<"\n After Set Matrix Zero : \n";
      for(int i = 0 ; i < m ;i++){
        for(int j = 0; j< n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}



void better(vector<vector<int>> &arr){

    int m = arr.size();//row
    int n = arr[0].size();//col

    vector<int> row(m,0),col(n,0);

    for(int i = 0 ; i < m ;i++){
        for(int j = 0; j< n;j++){
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

   for(int i = 0 ; i < m ;i++){
        for(int j = 0; j< n;j++){
            if(row[i] || col[j])
            arr[i][j] = 0 ;
        }
    }


     cout<<"\n After Set Matrix Zero (Brute) : \n";
      for(int i = 0 ; i < m ;i++){
        for(int j = 0; j< n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}



void brute(vector<vector<int>> &arr){
    int m = arr.size();
    int n = arr[0].size();
    
    vector<int> markRow(m,0) , markCol(n,0);

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if(arr[row][col] == 0){
                markRow[row] = 1, markCol[col] = 1;
                // markRow(arr, row, n);//Opposite for the third paramater
                // markCol(arr, col, m);//Opposite for the third paramater
            }
        }    
    }

    for(int i = 0;i < m; i++){
        for (int j = 0; j < n; j++)
        {

            if(markRow[i] || markCol[j]){
                arr[i][j] = 0;
            }
            // if(arr[i][j] == -1){
            //     arr[i][j] = 0;
            // }
        }   
    }
}

void printMatrix(vector<vector<int>> &arr){
    for(auto &i : arr){
        for(auto it : i){
            cout<< it << " ";
        }
        cout<<endl;
    }
}

int main()
{

    vector<vector<int>> arr = {{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};
    // vector<vector<int>> arr = {{-1},{2},{3}};

    cout<<"Original Matrix: \n";
    printMatrix(arr);

    // brute(arr);
    // better(arr);
    optimal(arr);

    
    // cout<<"\n After Set Matrix Zero (Brute) : \n";
    // printMatrix(arr);

    return 0;
}