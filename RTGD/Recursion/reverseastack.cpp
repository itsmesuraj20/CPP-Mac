#include<bits/stdc++.h>
using namespace std;

void insertStack(stack<int> &st , int temp)
{
    if(st.empty()){
        st.push(temp);
        return ;
    }

    int top = st.top();
    st.pop();

    insertStack(st,temp);

    st.push(top);

}

void reverseStack(stack<int> &st){

    if(st.empty()){
        return ;
    }

    int topele = st.top();
    st.pop();

    reverseStack(st);

    insertStack(st,topele);

}

int main(){

    // vector<int> arr = {1,2,3};
     
    vector<int> arr = {3,2,1}; 
    
    stack<int> st;

    //Pushing it arr to stack 
    for(int i :arr){
        st.push(i);
    }

    reverseStack(st);

    while(!st.empty())
    {

        cout<< st.top() << " ";
        st.pop();

    }
    
    return 0;
}