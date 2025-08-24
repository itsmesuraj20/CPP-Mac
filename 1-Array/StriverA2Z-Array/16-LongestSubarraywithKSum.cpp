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


void generateSubArrayRecursively(vector<int>& arr, int start, int end) 

{
    // Stop if we have reached the end of the array
    if (end == arr.size())
        return;

    // Increment the end point and reset the start to 0
    else if (start > end)
        generateSubArrayRecursively(arr, 0, end + 1);

    // Print the subarray and increment the starting point
    else {
        for (int i = start; i <= end; i++)  
            cout << arr[i] << " ";

        cout << endl;

        generateSubArrayRecursively(arr, start + 1, end);  
    }
}



int main(){
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};

    int k;

    cout<<arr.size()<<endl;
    generateSubArrayBruteMethod(arr);
    generateSubArrayRecursively(arr, 0 , 0);
    

    return 0;
}