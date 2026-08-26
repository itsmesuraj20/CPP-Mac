#include<bits/stdc++.h>
using namespace std;
void solve(int n , char src , char help ,char desti, int &c){
//updated a serial number
    if(n == 0){
        cout<<endl;
        return;
    }

    solve(n-1,src,desti,help,c);
    cout << ++c << " : Disk " << n << " from " << src << " to " << desti << endl;
    solve(n-1,help,src,desti,c);

}
int main(){
    
    int n = 4 ; 
    int c = 0;

    char s = 'a';
    char h = 'b';
    char d = 'c';

    solve(n, s,h,d,c);

    return 0;

}