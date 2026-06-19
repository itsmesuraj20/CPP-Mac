#include<bits/stdc++.h>
using namespace std;

void insert(){

}

void delete(stack<int> &st , int k)
{
    if(k == 1)
    {
        st.pop();
        return; 
    }

    int val = st.top();
    st.pop();

    delete(st,k-1);

    insert(st);

}

int main(){

    stack<int> st;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    delete(st , k);

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}