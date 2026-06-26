//Practice session on Codechef Compiler 

#include <bits/stdc++.h>
using namespace std;

//SortanArray

//SortanStack

//Deletethemiddleelement

void insertFunc(vector<int> &arr, int temp){
    
    if(arr.size() == 0 || arr[arr.size()-1] <=temp){
        arr.push_back(temp);
        return;
    }
    
    int val = arr[arr.size()-1];
    arr.pop_back();
    
    
    insertFunc(arr,temp);
    
    arr.push_back(val);
    
}

void SortanArray(vector<int> &arr){
    
    if(arr.size() == 1){
        return ;
    }
    
    int temp = arr[arr.size() - 1];
    arr.pop_back();
    SortanArray(arr);
    insertFunc(arr,temp);
}

//st.pop();
//st.top();
//st.empty();
//st.push();

void insertStack(stack<int> &st , int temp){
    
    if(st.empty() || st.top() <= temp){
        st.push(temp);
        return;
    }
    
    int val = st.top();
    st.pop();
    
    insertStack(st,temp);
    
    st.push(val);
    
}

void SortanStack(stack<int> &st){
    if(st.empty())
    return;
    
    int temp = st.top();
    st.pop();
    
    SortanStack(st);
    insertStack(st, temp);
}

// void insertStack4Del(stack<int> &st , int temp){
//     if(st.empty() || st.top() <= temp){
//         st.push(temp);
//         return;
//     }
    
//     int val = st.top();
//     st.pop();
    
//     insertStack4Del(st,temp);
//     st.push(val);
    
// }

void deleteMiddle(stack<int> &st , int k){
    
    if(k== 1){
        st.pop();
        return;
    }
    
    int temp = st.top();
    st.pop();
    
    deleteMiddle(st,k-1);
    
    st.push(temp);
    
}

int main() {
	// your code goes here
	vector<int> arr = {2 , 1, 0 ,5 ,4};
	stack<int> st ;
	
	st.push(2);
	st.push(1);
// 	st.push(0);
	st.push(5);
	st.push(4);
	
// 	SortanArray(arr);
	
    SortanStack(st);
    
    int k = st.size() / 2  + 1;
   
    // k = (k / 2) + 1;
    
    // deleteMiddle(st, k);
    
    
    // for(int i :arr){
    //     cout<< i << " "; 
    // }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
