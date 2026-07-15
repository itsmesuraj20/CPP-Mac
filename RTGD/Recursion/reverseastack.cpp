// #include<bits/stdc++.h>
// using namespace std;

// void insertStack(stack<int> &st , int temp)
// {
//     if(st.empty()){
//         st.push(temp);
//         return ;
//     }

//     int top = st.top();
//     st.pop();

//     insertStack(st,temp);

//     st.push(top);

// }

// void reverseStack(stack<int> &st)
// {
//     if(st.size() == 1){
//         return ;
//     }

//     int topele = st.top();
//     st.pop();

//     reverseStack(st);

//     insertStack(st,topele);
// }

// int main(){

//     // vector<int> arr = {1,2,3};
//     // vector<int> arr = {7,0,4};

//     // vector<int> arr = {3,2,1};

    
//     // //Pushing it arr to stack 
//     // for(int i :arr){
//         //     st.push(i);
//         // }
        
//     stack<int> st;

//     st.push(1);
//     st.push(2);
//     st.push(4);
//     st.push(7);

//     reverseStack(st);

//     while (!st.empty()) {
//         cout << st.top() << " ";
//         st.pop();
//     }   

//     return 0;

// }


#include <bits/stdc++.h>
using namespace std;

//Sort an Array 
//2 function 

void insertArr(vector<int> &arr,int temp){
    int n = arr.size();
    if(arr.empty() || arr[n-1] <= temp)
    {
        arr.push_back(temp);
        return ;
    }
    
    int val = arr[n-1];
    arr.pop_back();
    
    insertArr(arr,temp);
    
    arr.push_back(val);
}

void sortArr(vector<int>& arr){
    int n = arr.size();
    if(arr.size() == 0){
        return ;
    }
    
    int top = arr[n-1];
    arr.pop_back();
    
    sortArr(arr);
    
    insertArr(arr,top);
}
//Sort a Stack

// void insertStack(stack<int>&st, int temp){
    
//     if(st.empty() || st.top() <= temp){
//         st.push(temp);
//         return;
//     }
    
//     int val = st.top();
//     st.pop();
    
//     insertStack(st,temp);
//     st.push(val);
// }

// void sortStack(stack<int> &st){
    
//     if(st.empty()){
//         return ;
//     }
    
//     int temp = st.top();
//     st.pop();
    
//     sortStack(st);
    
//     insertStack(st,temp);
// }

//Delete middle element in the stack 
// void deletemiddle(stack<int>&st ,  int mid ){
//     if(mid==1){
//         st.pop();
//         return ;
//     }
    
//     int top = st.top();
//     st.pop();
    
//     deletemiddle(st,mid-1);
//     // insertStack(st,top);
//     st.push(top);
// }

//Put the last element for the popped stack;
void insertatLast(stack<int> &st ,int top){
    if(st.empty()){
        st.push(top);
        return;
    }
    
    int topele = st.top();
    st.pop();
    insertatLast(st,top);
    st.push(topele);
}
//Reverse the stack 

void reverseStack(stack<int> &st){
    if(st.size() == 1){
        return;
    }
    
    int top = st.top();
    st.pop();
    
    reverseStack(st);
    insertatLast(st,top);
    
}

int main() {
// 	vector<int> arr = {1,4,7,0,5,2};
    // vector<int> arr = {1,2,3,4,5,6,7};	
    vector<int> arr = {1,2,3};
// 	stack<int , vector<int>> st(arr);

    stack<int> st;
    
    for(int i : arr)
    {
        st.push(i);
    }

    cout<<"Before operation at the stack"<<endl;
    
     while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
    cout<<endl;
    
    
    for(int i : arr){
        st.push(i);
    }
	
// 	int n = st.size();
// 	int m = n/2 + 1 ; 
// 	sortArr(arr);
//     //Printing the arr
//     for(int i : arr){
//         cout<< i << " ";
//     }
    
//     cout<<endl;
    
    // sortStack(st);
    // deletemiddle(st,m);
    reverseStack(st);
    //Print the stack
    
    
    cout<<"After operation at the stack"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}
