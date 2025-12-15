#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Sumcheck_Brute(vector<int> &arr)
{
    int n = arr.size();

    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]}; // Possible array ko store kiya hai 
                    sort(temp.begin(), temp.end()); // Sort kiya jisse redundant value store na ho
                    st.insert(temp); // set mein insert kr diya simple
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end()); // set internally keeps elements sorted and unique; this line just materializes that into a vector
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> Sumcheck = Sumcheck_Brute(arr);

    for (auto &x : Sumcheck)
    {
        for (int i : x)
        {
            cout << i << " ";
        }
        cout<<endl;
    }

    return 0;
}