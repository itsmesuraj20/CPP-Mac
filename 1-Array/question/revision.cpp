#include<iostream>
#include<set>

using namespace std;

int bruteCheck(vector<int> &arr){
    set<int> s;
    int n = arr.size();

    for(int i = 0 ;i<n;i++){
        s.insert(arr[i]);
    }

    arr.clear();

    for(auto i : s){
        arr.push_back(i);
    }

    return arr.size();

}


int main(){
    vector<int> arr = {1,1,1,2,2,3,3,3,3};

    cout<<bruteCheck(arr);
}