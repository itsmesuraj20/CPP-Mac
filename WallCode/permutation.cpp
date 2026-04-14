#include<bits/stdc++.h>
using namespace std;

void per(int ind , vector<int> num , vector<vector<int>> result){

    int n = num.size();

    if( ind == n ){
        result.push_back(num);
        return ;
    }

    for (int i = ind; i < n; i++)
    {
        swap(num[ind] , num[i]);
        per(ind + 1, num,result);
        swap(num[ind] , num[i]);

    }
}

int main()
{
    return 0;
}