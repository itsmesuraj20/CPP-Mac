#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralMatrixFunction(vector<vector<int>> &arr){

    vector<int> ans;
    if(arr.empty() || arr[0].empty()) return ans;

    int rows = arr.size();
    int cols = arr[0].size();

    int top = 0,left = 0;
    int bottom = rows - 1, right = cols - 1;

    while(top <= bottom && left <= right)
    {
        
        for (int i = left; i <= right; i++)
        {
            ans.push_back(arr[top][i]);
        }

        top++;

        for(int i = top ; i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;

        if(top <= bottom){
            for(int i = right;i >= left ; i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        if(left <= right){
            for (int i = bottom; i>= top ; i--)
            {
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};

    vector<int> ans = spiralMatrixFunction(arr);

    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";

}