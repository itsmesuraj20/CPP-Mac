//Algo-1 for Greedy Algorithm
// Greedy Algorithm

#include<bits/stdc++.h>
using namespace std;
// Greedy Algorithm 

// Greedy algorithms are a class of algorithms that make a series of choices, each of which looks best at the moment.
// They are used to solve optimization problems, where the goal is to find the best solution from a set of feasible solutions.

int main(){
    // Example: Coin Change Problem
    // Given a set of coin denominations and a target amount, find the minimum number of coins needed to make the target amount.
    
    vector<int> coins = {1, 5, 10, 25}; // Coin denominations
    int target = 63; // Target amount
    int count = 0; // Number of coins used

    for(int i = coins.size() - 1; i >= 0; i--){
        while(target >= coins[i]){
            target -= coins[i];
            count++;
        }
    }

    cout << "Minimum number of coins needed: " << count << endl;

    return 0;
}
// TC : O(n)
// SC : O(1)