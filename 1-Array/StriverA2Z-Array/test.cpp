#include<iostream>
using namespace std;

int main (){
    int n ;
    string s;
    cin>>n;
    cin>>s;
    if(s.find("tea") != string ::npos){
        cout<< "Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}