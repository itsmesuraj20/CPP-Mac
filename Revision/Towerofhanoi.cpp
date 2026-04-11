#include <bits/stdc++.h>
using namespace std;

void solve(int n, int source, int destination, int helper) {
    if (n == 0) return;

    solve(n - 1, source, helper, destination);

    cout << "Move Disk " << n 
         << " from " << source 
         << " to " << destination << endl;

    solve(n - 1, helper, destination, source);
}

int main() {
    int n = 3;


    solve(n, 1, 3, 2);

    return 0;
}