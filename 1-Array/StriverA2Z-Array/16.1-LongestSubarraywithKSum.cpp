#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void longestSubArrayBetterMethod(vector<int> arr, int K) {
    // By Striver
    auto start = chrono::high_resolution_clock::now(); // START TIMER

    // O(N^2) time complexity
    // O(1) space complexity 
    int n = arr.size();
    int len = 0;

    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = i; j < n; j++) {
            s += arr[j];
            if (s == K)
                len = max(len, j - i + 1);
        }
    }

    auto end = chrono::high_resolution_clock::now();   // END TIMER
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Longest Subarray Length = " << len << endl;
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

void longestSubArrayBruteMethodYT(vector<int> &arr, int K) {
    // By Striver
    int n = arr.size();
    int len = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int s = 0;
            for (int k = i; k <= j; k++) {
                cout << "Before s : " << s << endl;
                s += arr[k];
                cout << "After s : " << s << endl;
            }

            if (s == K) {
                cout << "Before len : " << len << endl;
                len = max(len, j - i + 1);
                cout << "After len : " << len << endl;
            }
        }
    }

    cout << "Longest Subarray Length " << len << endl;
}

void longestSubArrayBruteMethod(vector<int> &arr, int K) {
    // ChatGPT with indices
    int n = arr.size();
    int len = 0;
    int start = -1, end = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int s = 0;
            for (int k = i; k <= j; k++) {
                s += arr[k];
            }

            if (s == K && (j - i + 1) > len) {
                len = j - i + 1;
                start = i;
                end = j;
            }
        }
    }

    cout << "Longest Subarray Length = " << len << endl;
    if (start != -1) {
        cout << "Start Index = " << start << ", End Index = " << end << endl;
        cout << "Subarray = ";
        for (int i = start; i <= end; i++) cout << arr[i] << " ";
        cout << endl;
    } 
    else {
        cout << "No subarray with sum " << K << " found" << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    int k = 6;

    // longestSubArrayBruteMethod(arr, k);
    // longestSubArrayBruteMethodYT(arr, k);
    longestSubArrayBetterMethod(arr, k);

    return 0;
}