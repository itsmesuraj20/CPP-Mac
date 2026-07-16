#include<bits/stdc++.h>
using namespace std;
//EkDum correct h , wo array ki wajah se lg raha hai tumhe so dont be confuse 
//Copy mein bhi dryrun kiya hai 

//Correct version of the recursive 

//Reverse the stack
void insertfunction(stack<int> &st , int element){
    if(st.empty()){
        st.push(element);
        return ;
    }

    int top = st.top();
    st.pop();

    insertfunction(st,element);
    st.push(top);
}

void stackfunction(stack<int> &st){
    if(st.empty() || st.size() == 1){
        return;
    }

    int top = st.top();
    st.pop();

    stackfunction(st);
    insertfunction(st,top);
}
int main(){

    vector<int> arr = { 3,2,1};

    stack<int> st;

    for(int i : arr){
        st.push(i);
    }
    
    stackfunction(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}