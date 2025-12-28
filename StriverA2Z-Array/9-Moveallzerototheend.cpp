#include<iostream>
using namespace std;
#define vi vector<int>

// Brute Better Optimal

vi brute(vi nums){
    //By me 
    vi newArr;

    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0){
            newArr.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            i--;
        }
    }

    for (int i = 0; i < newArr.size(); i++)
        nums.push_back(newArr[i]);


        return nums;

    //TC : O(n²) (erase operation costly)
    // SC : O(n)

}


vi better(vi nums){
    //By striver
    vi newArr;
    int n = nums.size();

    for(int i = 0;i<n;i++){
        if(nums[i] != 0)
        newArr.push_back(nums[i]);
    }

    for(int j = 0;j<newArr.size();j++)
        nums[j] = newArr[j]; 
    
    for(int k = newArr.size();k<n;k++)
    nums[k] = 0;

    return nums;

// TC : O(n)
// SC : O(n)

}

vector<int> optimal(vi &nums)
{

    int n = nums.size();

    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if(nums[i] == 0)
        {
            j = i;
            break;
        }
    }

     if(j == -1) return nums;

    for (int i = j+1; i < n; i++)
    {
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
    
    return nums;

// TC : O(n)
// SC : O(1) 

    
}



int main()
{

    vector<int> nums = {0,0,1};

    vector<int> ans = brute(nums);
    vector<int> ans = better(nums);
    vector<int> ansOptimal = optimal(nums);

    for (auto &&i : ansOptimal)
    {
        cout<<i<<" ";
    }
    
    return 0;

}