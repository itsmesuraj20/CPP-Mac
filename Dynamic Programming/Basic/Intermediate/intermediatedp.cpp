#include<bits/stdc++.h>
using namespace std;
// Intermediate Dynamic Programming

int main(){
    // Example: Longest Common Subsequence (LCS)
    // Given two strings, find the length of their longest common subsequence.
    
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    int m = str1.length();
    int n = str2.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << "Length of LCS: " << dp[m][n] << endl;
    
    return 0;
}
// TC : O(m*n)
// SC : O(m*n)