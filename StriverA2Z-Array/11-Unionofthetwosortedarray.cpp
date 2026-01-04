#include<iostream>
#include<set>

using namespace std;

/*
Find the union of the two sorted array :
arr1 = [1,2,3,4,5,5,6];
arr2 = [2,3,3,4,4,5];

o/p = [1,2,3,4,5,6];



Brute - Optimal (No Better)
*/

vector<int> union_Brute(vector<int> arr1,vector<int> arr2)
{

    //Set bnao usme dono array ke element push kar do then wapis  ek new answer array mein push kar do;

    vector<int> ans ;

    int n = arr1.size(); 
    int m = arr2.size();

    set<int> s;

    for (int i = 0; i < n; i++)
    {
       s.insert(arr1[i]);
    }

    for(int j = 0 ;j<m ; j++){
        s.insert(arr2[j]);
    }

    for(auto i : s){
        ans.push_back(i);
    }
    
    return ans;

    //TC : O 2(n+m log n*m) + O(3n) = 
    // TC : O(n log n )
    //SC : O (n log n)

}

vector<int> union_Optimal(vector<int> arr1,vector<int> arr2){
    //
    vector<int> ans;

    int n = arr1.size(); 
    int m = arr2.size();
    int i = 0, j = 0;


    while(i< n && j<m)0-\
?>g bcdfxv ̑QA2{
        if(arr1[i] <= arr2[j]) {
            if(ans.empty() || ans.back() != arr1[i]){
                ans.push_back(arr1[i]);
                
            }
            i++;
        }
        else{
           if(ans.empty() || ans.back() != arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
    } 

    while (i < n) {
        if (ans.empty() || ans.back() != arr1[i]) {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m) {
        if (ans.empty() || ans.back() != arr2[j]) {
            ans.push_back(arr2[j]);
        }
        j++;
    }

    return ans;
    
}

int main(){

    vector<int> arr1 = {1,2,3,4,5,5,6};
    vector<int> arr2 = {2,3,3,4,4,5};
    
    cout<<"Size of both array is :" << arr1.size() + arr2.size()<<endl;
    // vector<int> arr1 = {};
    // vector<int> arr2 = {};


    vector<int> ans = union_Optimal(arr1,arr2);
    cout<<"Size of the array is :" << ans.size()<<endl;
    for(int i :  ans){
        cout<<i<<" ";
    }

    return 0;
}