//Divide and Conquer
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cassert>

using namespace std;

// Function to find the maximum subarray sum using divide and conquer
int maxCrossingSum(const vector<int>& arr, int left, int mid, int right) {
    int sum = 0;
    int leftSum = numeric_limits<int>::min();
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    sum = 0;
    int rightSum = numeric_limits<int>::min();
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    return max(leftSum + rightSum, max(leftSum, rightSum));
}

int maxSubArraySum(const vector<int>& arr, int left, int right) {
    if (left == right) {
        return arr[left];
    }
    int mid = (left + right) / 2;
    return max(max(maxSubArraySum(arr, left, mid), maxSubArraySum(arr, mid + 1, right)), maxCrossingSum(arr, left, mid, right));
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();
    int maxSum = maxSubArraySum(arr, 0, n - 1);
    cout << "Maximum contiguous sum is " << maxSum << endl;
    return 0;
}
