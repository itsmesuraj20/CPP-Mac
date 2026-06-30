#include<bits/stdc++.h>
using namespace std;

void deleteElement(stack<int> &st , int k ){

    if(k == 1) {
        st.pop();
        return;
    }

    int top = st.top();
    st.pop();

    deleteElement(st,k-1);
    
    st.push(top);
}

int main(){
    stack<int> st;

    st.push(2);
    st.push(1);
    st.push(0);
    st.push(9); 

    int k = st.size()/2 + 1;

    deleteElement(st,k);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}