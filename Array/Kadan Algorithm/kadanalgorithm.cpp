//Kadan Algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to find the maximum sum of a contiguous subarray using Kadane's Algorithm       

int kadaneAlgorithm(const vector<int>& arr) {
    int maxSum = arr[0]; // Initialize maxSum with the first element
    int currentSum = arr[0]; // Initialize currentSum with the first element

    for (size_t i = 1; i < arr.size(); ++i) {
        currentSum = max(arr[i], currentSum + arr[i]); // Update currentSum
        maxSum = max(maxSum, currentSum); // Update maxSum if needed
    }

    return maxSum;
}
// Example usage    

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example array
    int maxSum = kadaneAlgorithm(arr); // Call the function
    cout << "Maximum sum of contiguous subarray: " << maxSum << endl; // Output the result
    return 0;
}
// Output: Maximum sum of contiguous subarray: 6
// Explanation: The contiguous subarray with the maximum sum is [4, -1, 2, 1], which has a sum of 6.
// Time Complexity: O(n)
// Space Complexity: O(1)
// This implementation uses Kadane's Algorithm to find the maximum sum of a contiguous subarray in linear time.
// It iterates through the array, maintaining the current sum and updating the maximum sum as needed.