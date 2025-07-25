#include<iostream>
#include<set>

using namespace std;

vector<int> bruteCheck(vector<int> &arr){
    set<int> s;
    int n = arr.size();

    for(int i = 0 ;i<n;i++){
        s.insert(arr[i]);
    }

    arr.clear();

    for(auto i : s){
        arr.push_back(i);
    }

    return arr;

}


int main(){
    vector<int> arr = {1,1,1,2,2,3,3,3,3};

    vector<int> newarr = bruteCheck(arr);

    for(int i = 0;i<newarr.size();i++){
        cout<<newarr[i]<< " ";
    }
}