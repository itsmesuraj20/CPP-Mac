#include<bits/stdc++.h>
using namespace std;
//No optimization are required in this problem
//As it has only one solution 

//Spiral Matrix
vector<vector<int>> spiralmatrixBuilderFunction(){

}

int main(){

vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
int rows = arr.size();
int cols = arr[0].size();
vector<vector<int>> ans;
    //top , bottom , left , right 

    int top = 0, left = 0;
    int bottom = row - 1 , right =  cols - 1;
while(top<= bottom || left <= right)
{
    for (int i = left; i <=right; i++)
    {
        ans.push_back(arr[top][i]);
    }

    top++;

    for (int i = top; i <= bottom; i++)
    {
       ans.push_back(arr[i][right]);
    }

    right--;

    for(int i = right ; i >= left ; i--){
        ans.push_back(arr[bottom][i]);
    }
    bottom-- ;

    for(int i= bottom ; i >= top ; i++ ){
        ans.push_back(arr[left][i]);
    }

    left++;
}
    

return 0;
}