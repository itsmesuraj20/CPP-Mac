#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/1703906517/
/*

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).


Suraj Understanding : Basic you have to remove the duplicate element to single element and then return the unique from the array

*/



/*
Quick Revision : 

Brute Method : 

- Set Table bnao jisme saare item ka insert krlo
- Then original array ko clear kardo arr.clear() se. 
- phir set table se Original array mein wapis item insert krke , return arr kardo .

TC - O(n log n);
SC - O(n);

Optimised Method : 


*/

int bruteMethod(vector<int> &arr)
 {

    //TC- O(n logn);
    //SC- O(n);

    set<int> setTable;

    for (int i = 0; i < arr.size(); i++)
    {
        setTable.insert(arr[i]);
    }
    
    arr.clear();

    for(auto it : setTable){
       arr.push_back(it);  
    }
    return arr.size();

 }

int optimizedMethod_RemoveDuplicates(vector<int> &arr){

    //TC-O(n)
    //SC -O(1)

    int i = 0;
    for(int j = 0;j<arr.size();j++){ 
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }

    return i+1;
}
vector<int> optimizedMethod_RemoveDuplicatesWithElement(vector<int> &arr){

    //TC-O(n)
    //SC -O(1)

    int i = 0;
    for(int j = 0;j<arr.size();j++){ 
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }

    return arr;
}


int main(){

    // vector<int> arr = {-1,1,2,-3};
    // vector<int> arr = {1,2,2,3,4};
    vector<int> arr = {1,1,2};

    if(arr.empty()){
        cout<<"Must have 1 value to proceed"<<endl;
    }

    else{
    // cout<<"Brute Method : " << bruteMethod(arr)<<"\n";    
    cout<<"Optimized Method : " << optimizedMethod_RemoveDuplicates(arr)<<"\n";
   vec optimizedMethod_RemoveDuplicatesWithElement(arr);
    for(int i : arr) cout<<i << " ";
    }

    return 0; 
}