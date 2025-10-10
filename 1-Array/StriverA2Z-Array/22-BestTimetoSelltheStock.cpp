#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int n = prices.size();
    
    int mini = prices[0];
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        int cost = prices[i] - mini;
        profit = max(prices , )    
    }
    
}

int main(){
    vector<int> arr = {7,1,5,3,6,4};

    cout<<"Max Profit : "<< maxProfit<<"\n";
    return 0;
}
