#include<iostream>
using namespace std;
// arr[] = {1,2,3,4,5,6,7} , d = 2
// O/P = {6,7,1,2,3,4,5}


vector<int> bruteRightRotate(vector<int> arr ,int d ){
    vector<int> temp;
    int n = arr.size();
    d=d%n;
    int end = n-d;

    for(int i = 0;i<end;i++){
        temp.push_back(arr[i]);
    }

    int j = 0;
    for(int i = n-d ;i<n;i++){
       arr[j] = arr[i];
        j++;
    }

        int k = d;
        for (int j = 0; j < temp.size(); j++)
        {
            arr[k] = temp[j];
            k++;
        }
    
    return arr;
}

vector<int> optimalRotate(vector<int> arr,int d){
    int n = arr.size();
    d=d%n;
    reverse(arr.begin(),arr.end() - d);
    reverse(arr.end() - d ,arr.end());
    reverse(arr.begin(),arr.end());
}
int main(){
    //  vector<int> arr = {1,2,3,4,5,6,7,8,9,0};
    //  vector<int> arr = {1,2,3,4,5,6,7};
    //  vector<int> arr = {-1,-100,3,99};

    vector<int> arr = {1,2,3,4,5};
     int d = 2;

    vector<int> newArr = bruteRightRotate(arr,d);
    // vector<int> newArr2 = optimalRotate(arr,d);

    for(int i : newArr){
        cout<<i<<" ";
    }
    return 0;

    return 0;
}