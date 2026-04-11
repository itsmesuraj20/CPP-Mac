#include <bits/stdc++.h>
using namespace std;

void solve(int n, int source, int destination, int helper) {
    if (n == 0) return;

    if (n == 1) {
        cout << "Move Disk " << source << " to " << destination << endl;
        return;
    }

    solve(n - 1, source, helper, destination);
    cout << "Move Disk " << source << " to " << destination << endl;
    solve(n - 1, helper, destination, source);
}

int main() {
    int n;
    cin >> n;

    solve(n, 1, 3, 2);

    return 0;
}