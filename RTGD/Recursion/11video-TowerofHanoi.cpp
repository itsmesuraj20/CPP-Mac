#include<bits/stdc++.h>
using namespace std;
void solve(int n , char src , char help ,char desti){
    int c = 1;
    if(n == 0){
        cout<<endl;
        return;
    }

    solve(n-1,src,desti,help);
    cout << c << " : Disk " << n << " from " << src << " to " << desti << endl;
    c++;
    solve(n-1,help,src,desti);

}
int main(){
    int n = 3 ; 
    
    char s = 'a';
    char h = 'b';
    char d = 'c';

    solve(n, s,h,d);

    return 0;

}`