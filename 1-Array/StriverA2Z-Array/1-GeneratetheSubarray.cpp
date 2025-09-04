#include <iostream>
using namespace std;

void generateSubArrayBrute(vector<int> &arr)
{
    int n = arr.size();
    cout << "Size : " << n << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
    }
}

int main()
{
    // vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    vector<int> arr = {1, 2, 3};

    generateSubArrayBrute(arr);

    return 0;
}