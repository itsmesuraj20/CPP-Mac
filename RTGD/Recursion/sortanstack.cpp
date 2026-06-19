#include<bits/stdc++.h>
using namespace std;

/*

st.push() -> add the element
st.pop() -> mean delete the element
st.top() -> top most element 
st.empty() -> Empty the stack

*/

void insertFunc(stack<int> &arr , int temp){
    if(arr.empty() || arr.top() <= temp){
        arr.push(temp);
        return ;
    }

    int val = arr.top();
    arr.pop();

    insertFunc(arr,temp);

    arr.push(val);
}

void stackSort(stack<int> & arr){
    
    if(arr.empty()){
        return ;
    }

    int temp = arr.top();
    arr.pop();

    stackSort(arr);

    insertFunc(arr,temp);
}


int main(){

    stack<int> s ;
    s.push(0);
    s.push(1);
    s.push(5);
    s.push(2);

    stackSort(s);
    
    while(!s.empty()){

    cout << s.top() << " ";

    s.pop();

}
    return 0;
}