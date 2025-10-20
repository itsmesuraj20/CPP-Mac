#include<bits/stdc++.h>
using namespace std;

/*Quick Recall -

Solution - i-> 1 index se chalao , and compare kro previous wale se , bool result = false,
and break kr jao . Return the answer.

*/

int main(){
    int arr1[] = {1,5,6,7,2,3,9};

    //This is the method to find the size of the array.
    int n = sizeof(arr1)/sizeof(arr1[0]);

    // cout<<n<<endl;
    //handle edge cases
    
    if(n == 0){
        cout<<"Array is Empty";
    }
    else if(n == 1){
        cout<<"Array is Sorted";
    }

    else
    {
    bool result = true;
    for (int i = 1; i < n; i++)
    {
       if(!(arr1[i] >= arr1[i-1])){
        result = false;
        break;
       }
    }

    if(result) 
    cout<<"Sorted in ascending order or Non-descending order" << endl;
    
    else 
    cout<<"Not Sorted" <<endl;
    
    }
}