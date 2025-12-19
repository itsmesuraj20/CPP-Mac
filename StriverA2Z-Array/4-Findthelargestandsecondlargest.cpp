/*
Largest and Second Largest 
Largest : 
Brute - Optimal

Second : 
Brute - Better - Optimal

*/


#include <bits/stdc++.h>
using namespace std;

int largestBruteMethod(vector<int> arr){

    sort(arr.begin(), arr.end());
    return arr.back();
    // TC - O(n log n), SC - O(1)

}

int secondLargestBruteMethod(vector<int> arr)
{

    sort(arr.begin(), arr.end());
    int largestSoFar = arr.back();
    for(int i = arr.size() - 2; i >= 0; i--){
        if(arr[i] != largestSoFar){
            return arr[i];
        }
    }
    return -1;
    // TC - O(n log n), SC - O(1)

}

int secondLargestBetter(vector<int> arr){
    int largestSoFar = largestOptimal(arr);
    int secondLargestSoFar = INT_MIN;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > secondLargestSoFar && arr[i] != largestSoFar){
            secondLargestSoFar = arr[i];
        }
    }
    return (secondLargestSoFar == INT_MIN) ? -1 : secondLargestSoFar;
    // TC - O(n), SC - O(1)
}

int largestOptimal(vector<int> arr)
{

    //Interview Generic;

    int largestSoFar = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > largestSoFar){
            largestSoFar = arr[i];
        }
    }
    return largestSoFar;

    // TC - O(n), SC - O(1)
    
    
    //                                      OR

    // int n = arr.size();
    // int largest = arr[0];
    
    // for(int i = 0 ; i < n; i++ )
    // {
    //     largest = max(largest,arr[i]);
    // }
    // return largest;

}

int secondLargestOptimal(vector<int> arr){
    int largestSoFar = arr[0];
    int secondLargestSoFar = INT_MIN;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > largestSoFar){
            secondLargestSoFar = largestSoFar;
            largestSoFar = arr[i];
        }
        else if(arr[i] < largestSoFar && arr[i] > secondLargestSoFar){
            secondLargestSoFar = arr[i];
        }
    }
    return (secondLargestSoFar == INT_MIN) ? -1 : secondLargestSoFar;
    // TC - O(n), SC - O(1)
}

// ✅ Test function to validate all edge cases
void runTests() {
    vector<pair<vector<int>, pair<int, int>>> testCases = {
        {{1, 2, 3, 4, 5}, {5, 4}},
        {{5, 1, 2, 5, 3}, {5, 3}},
        {{2, 2, 2, 2}, {2, -1}},
        {{-1, -2, -3}, {-1, -2}},
        {{10}, {10, -1}},
        {{}, {-1, -1}}
    };

    cout << "\nRunning Test Cases:\n";

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> arr = testCases[i].first;
        int expectedLargest = testCases[i].second.first;
        int expectedSecond = testCases[i].second.second;

        int actualLargest = -1;
        int actualSecond = -1;

        if (!arr.empty()) {
            actualLargest = largestOptimal(arr);
            actualSecond = secondLargestOptimal(arr);
        }

        cout << "Test Case " << i + 1 << ": ";
        assert(actualLargest == expectedLargest);
        assert(actualSecond == expectedSecond);
        cout << "✅ Passed\n";
    }

    cout << "✅ All tests passed successfully.\n\n";
}

// ✅ Main function
int main(){
    runTests();  // Call the test runner first

    vector<int> arr = {-1, -2, -3};  // You can change this to test manually

    if(arr.empty()){
        cout << "Array is empty, can't proceed" << endl;
    } else {
        cout << "Brute Method" << endl;
        cout << "Largest in the array : " << largestBruteMethod(arr) << endl;
        cout << "Second Largest in the array : " << secondLargestBruteMethod(arr) << endl;
        cout << "\n";

        cout << "Better Method" << endl;
        cout << "Largest in the array : " << largestBetter(arr) << endl;
        cout << "Second Largest in the array : " << secondLargestBetter(arr) << endl;
        cout << "\n";

        cout << "Optimal Method" << endl;
        cout << "Largest in the array : " << largestOptimal(arr) << endl;
        cout << "Second Largest in the array : " << secondLargestOptimal(arr) << endl;
    }

    return 0;
}