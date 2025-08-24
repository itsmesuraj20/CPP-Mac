#include<iostream>
using namespace std;

//Formula to determine the total number of subarray

/*

 N = Number of element of the array;
 Total Number of subarray = ( n * (n+1) / 2 );

*/

void generateSubArrayBruteMethod(vector<int> &arr){
    int n = arr.size();
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



int main(){
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};

    int k;

    cout<<arr.size()<<endl;
    generateSubArrayBruteMethod(arr);

    return 0;
}