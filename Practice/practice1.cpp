// Reverse a stack using recursion

#include <bits/stdc++.h>
using namespace std;
void insertStack(stack<int> &st, int temp)
{

    if (st.empty())
    {
        st.push(temp);
        return;
    }

    int temp_insert = st.top();
    st.pop();

    insertStack(st, temp);

    st.push(temp_insert);
}
void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    reverse(st);

    insertStack(st, temp);
}
int main()
{
  stack<int> st;

  st.push(1);
  st.push(2);
  st.push(3);

  cout<<"Before : "<<endl;
  
  //Creating a copy of the original;
  stack<int> temp = st;
  
  while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    reverse(temp);

    cout << "After : " << endl;

    while (!temp.empty())
    {
        cout << temp.top() << endl;
        temp.pop();
    }
    return 0;
}