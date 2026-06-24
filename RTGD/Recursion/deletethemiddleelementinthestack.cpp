#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &st ,int temp){
     if(st.empty() || st.top() <= temp){
        st.push(temp);
        return ; 
     }

     int val = st.top();
     st.pop();

     insert(st,temp);

     st.push(val);
}

void deleteStack(stack<int> &st , int k)
{
    if(k == 1)
    {
        st.pop();
        return; 
    }

    int temp = st.top();
    st.pop();

    deleteStack(st,k-1);

    insert(st ,temp);
}

int main(){

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);

    int n = st.size();

    int  k = n / 2  + 1;

    deleteStack(st,k);

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}