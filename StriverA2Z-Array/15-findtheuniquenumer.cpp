//Find the number that appears once , and the other twice.


#include<iostream>
#include<map>
using namespace std;


int usingBruteMethod(vector<int> &arr){
    
    int n = arr.size();

    for(int i= 0 ; i< n; i++)
    {
        int nums = arr[i];
        int cnt  = 0;

        for (int j = 0; j < n; j++)
        {
            if(arr[j] == nums){
                cnt++;
            }
        }
        if(cnt == 1) return nums;
    }
}

//TC - O(n^2)
//SC - O(1)


int usingBetterMethod(vector<int> &arr){
    unordered_map<long long , int> mp;

    for(int i = 0; i<arr.size(); i++ ){ 
        mp[arr[i]]++;
    }

    for(auto it :  mp){
        if(it.second == 1){
            return it.first;
        }
    }


}

int usingOptimalMethod(vector<int> &arr){
    int XOR = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        XOR = XOR^arr[i];
    }

    return XOR;
    
}

int main(){

    vector<int> arr = {1,1,2,3,3,4,4};

    cout<<"Using Brute Way : " << usingBruteMethod(arr) << endl;
    cout<<"Using Better Way : " << usingBetterMethod(arr) << endl;
    cout<<"Using Optimal Way : " << usingOptimalMethod(arr) << endl;

}