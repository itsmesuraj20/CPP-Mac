//LC 2149 : https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

/*
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  
*/

#include <bits/stdc++.h>
using namespace std;

// Brute force approach: O(N) time, O(N) space
// Separates positive and negative numbers into two arrays, then merges them
vector<int> BruteForceRearrange(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result = arr;  // Create a copy to avoid modifying original
    
    vector<int> positive_numbers; 
    vector<int> negative_numbers; 

    // Separate positive and negative numbers
    for (int i = 0; i < n; i++) {
        if (result[i] > 0) {
            positive_numbers.push_back(result[i]);
        } else {
            negative_numbers.push_back(result[i]);
        }
    }

    // Merge them in alternating positions
    for (int i = 0; i < n / 2; i++) {
        result[2 * i] = positive_numbers[i];
        result[2 * i + 1] = negative_numbers[i];
    }

    return result;
}

// Optimal approach: O(N) time, O(N) space
// Single pass solution using two pointers
vector<int> OptimalRearrange(const vector<int>& arr) {
    int n = arr.size();
    
    int positive_index = 0;
    int negative_index = 1;
    
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            result[positive_index] = arr[i];
            positive_index += 2;
        } else {
            result[negative_index] = arr[i];
            negative_index += 2;
        }
    }

    return result;
}

// Helper function to print array
void PrintArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {3, -2, 1, -5, 2, -4};
    
    cout << "Original Array: ";
    PrintArray(arr);
    
    cout << "\nBrute Force Approach: ";
    vector<int> brute_result = BruteForceRearrange(arr);
    PrintArray(brute_result);
    
    cout << "Optimal Approach: ";
    vector<int> optimal_result = OptimalRearrange(arr);
    PrintArray(optimal_result);

    return 0;
}