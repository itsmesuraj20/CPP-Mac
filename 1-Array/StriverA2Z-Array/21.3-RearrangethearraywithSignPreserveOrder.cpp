// Rearrange the order without preserver the order of the element dont like previous one


#include<bits/stdc++.h>
using namespace std;

vector<int> SingleSolutionforthisQuestion(vector<int> &arr){
    int n = arr.size();
    vector<int> pos, neg;
    
    for(int i = 0;i < n ; i++){
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    for()

}


int main(){
    vector<int> arr = {3,-2,1,-2,9,6,1,0};

    vector<int> SingleSolutionforthisQuestion(arr);
    return 0;
}

