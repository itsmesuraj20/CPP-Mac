#include<bits/stdc++.h>
using namespace std;

void insertforReversal(stack<int> &st, int top)
{

    if(st.empty()){
        st.push(top);
        return ; 
    }

    int topEle = st.top();
    st.pop();

    insertforReversal(st,top);
    st.push(topEle);
}

void reverse(stack<int> &st){
    
    if(st.empty()){
        return ;
    }

    int top = st.top();
    st.pop();

    reverse(st);
    insertforReversal(st,top);

}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<"Before"<<endl;

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    cout<<"\n";

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse(st);

    cout<<"After"<<endl;

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
    
}