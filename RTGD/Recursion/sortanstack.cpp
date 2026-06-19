#include <bits/stdc++.h>
using namespace std;

//Sort an stack , exactly like sort an array 

//st.top();
//st.empty();
//st.pop();
//st.push();

void insert(stack<int>&st , int temp){
    if(st.empty() || st.top()<= temp){
        st.push(temp);
        return;
    }
    
    int val = st.top();
    st.pop();
    
    insert(st,temp);
    
    st.push(val);
}

void sortStack(stack<int> &st){
    
    if(st.empty()){
        return ;
    }
    
    int temp = st.top();
    
    st.pop();
    
    sortStack(st);
    
    insert(st,temp);
}

int main() {
    
	stack<int> st;
	st.push(0);
	st.push(1);
	st.push(5);
	st.push(2);
	
	sortStack(st);
	
	while(!st.empty()){
	    cout<<st.top()<<" ";
	    st.pop();
	}
	
	return 0;
}
