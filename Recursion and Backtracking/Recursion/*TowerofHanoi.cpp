#include <bits/stdc++.h>
using namespace std;

void solve(int n, int source, int destination, int helper)
{
    if (n == 0)
    {
        cout << " Cant proceed because of Zero Disk ";
        return;
    }

    if(n == 1) {
        cout<<"Disk Move from "<< source << " to " << destination << endl;
        return;
    }


    solve(n-1, source, helper , destination);
    cout<<"Move from " << source << " to " << destination <<endl;
    solve(n-1,helper , destination , source);

}
int main()
{
    int n;
    cin >> n;

    int source = 1, destination = 3, helper = 2;

    solve(n, source, destination, helper);

    return 0;
}