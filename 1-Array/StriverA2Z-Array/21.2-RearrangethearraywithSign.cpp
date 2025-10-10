#include<bits/stdc++.h>
using namespace std;

// Question say that the number of psitive and negative elements are not same like the previous one;

//[-1,2,3,4,-3,1]
//[2,-1,3,-3,4,1]

//Approach - Kya rahegi samjho -> pos[2,3,4,1] and neg[-1,-3]
//Approach - pos
// arr[]


// vector<int> BruteOnlySolution(vector<int> arr)
// {
//     int n = arr.size();
//     vector<int> pos,neg;

//     for (int i = 0; i < n; i++)
//     {
//        if( arr[i] > 0) pos.push_back(arr[i]);
//        else neg.push_back(arr[i]);
//     }
    

//     vector<int> res;
//     for (int i = 0; i < n; i++)
//     {
//         res.push_back(pos[i]);
//         res.push_back(neg[i]);
//     }
//     return res;
// }


vector<int> BruteOnlySolution(vector<int> arr)
{
    int n = arr.size();
    vector<int> pos, neg;

    // Separate positive and negative numbers
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    // Merge alternately
    vector<int> res;
    for (int i = 0; i < pos.size(); i++)
    {
        res.push_back(pos[i]);
        res.push_back(neg[i]);
    }

    return res;
}

vector<int> BruteForceSolutionByStriver(vector<int> &arr){

    int n = arr.size();

    vector<int> pos , neg;

    //Filtering according to the element sign.
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    vector<int> ans(n,0);
    int limit = min(pos.size(),neg.size());
    
    for(int i = 0 ; i < limit ;i++)
    {

        ans[i*2] = pos[i];
        ans[i*2 + 1] = neg[i];
    
    }

    int ind = limit * 2;

    for (int i = limit; i < pos.size(); i++)
    {
       ans[ind] = pos[i];
       ind++;
    }

    return ans;
}

int main(){

    vector<int> arr = { 3,-2,-1,5,4,-3,9,-9};

    // vector<int> AnswerArray = BruteOnlySolution(arr);
    vector<int> AnswerArray = BruteForceSolutionByStriver(arr);

    for(int it : AnswerArray){
        cout<<it<<" ";
    }

    return 0;
}