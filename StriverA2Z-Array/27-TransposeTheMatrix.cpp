#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int rows = arr.size();
    if (rows == 0)
        cout << "Not Possible" << endl;

    int cols = arr[0].size();

    // Case 1: Square Matrix -> Transpose in-place copy
    if (rows == cols)
    {
        vector<vector<int>> result = arr;
        for (int i = 0; i < rows; i++)
        {
            for (int j = i + 1; j < cols; j++)
            {
                swap(result[i][j], result[j][i]);
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout<<endl;
    cout<<"Case 2"<<endl;
    cout<<endl;

    // Case 2 : Rectangular Matrix -> create new matrix

    vector<vector<int>> resultRectangle(cols, vector<int>(rows));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            resultRectangle[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << resultRectangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}