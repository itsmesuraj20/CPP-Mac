#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

/*

Longest SubArray with K Sum 
Here is the list of variation of Longest SubArray with K Sum problems:
1- Longest SubArray with K Sum (Positive Numbers)
2- Longest SubArray with K Sum (Negative Numbers)
3- Longest SubArray with K Sum (Positive + Negative Numbers)
4- Longest SubArray with K Sum (Circular Array)
5- Longest SubArray with K Sum (Binary Array)
6- Longest SubArray with K Sum (2D Array)
7- Longest SubArray with K Sum (Count of such SubArrays)
8- Longest SubArray with K Sum (Print all such SubArrays)
9- Longest SubArray with K Sum (Smallest such SubArray)
10- Longest SubArray with K Sum (Largest such SubArray)
11- Longest SubArray with K Sum (Count of such SubArrays)
12- Longest SubArray with K Sum (Print all such SubArrays)
13- Longest SubArray with K Sum (Smallest such SubArray)
14- Longest SubArray with K Sum (Largest such SubArray)
15- Longest SubArray with K Sum (Count of such SubArrays)
16- Longest Subarray with K Sum (At Most K)
17- Longest Subarray with K Sum (Exactly K)
18- Longest Subarray with K Sum (At Least K)
19- Longest Subarray with K Sum (Multiple of K)
20- Longest Subarray with K Sum (Divisible by K)
21- Longest Subarray with K Sum (Not Divisible by K)
22- Longest Subarray with K Sum (Sum of Elements is K)
23- Longest Subarray with K Sum (Product of Elements is K)
24- Longest Subarray with K Sum (Difference of Elements is K)
25- Longest Subarray with K Sum (Sum of Squares of Elements is K)
26- Longest Subarray with K Sum (Sum of Cubes of Elements is K)
27- Longest Subarray with K Sum (Sum of Even Elements is K)
28- Longest Subarray with K Sum (Sum of Odd Elements is K)
29- Longest Subarray with K Sum (Sum of Positive Elements is K)
30- Longest Subarray with K Sum (Sum of Negative Elements is K)
31- Longest Subarray with K Sum (Sum of Distinct Elements is K)
32- Longest Subarray with K Sum (Sum of Non-Distinct Elements is K)
33- Longest Subarray with K Sum (Sum of Prime Elements is K)
34- Longest Subarray with K Sum (Sum of Composite Elements is K)
35- Longest Subarray with K Sum (Sum of Fibonacci Elements is K)
36- Longest Subarray with K Sum (Sum of Perfect Square Elements is K)
37- Longest Subarray with K Sum (Sum of Perfect Cube Elements is K)
38-	Longest Subarray with K Sum (Modulo m)
39- Longest Subarray with K Sum (XOR is K)
40- Longest Subarray with K Sum (AND is K)
41- Longest Subarray with K Sum (OR is K)
42- Longest Subarray with K Sum (Bitwise Operations)
43- Longest Subarray with K Sum (Sliding Window Technique)
44- Longest Subarray with K Sum (Prefix Sum Technique)
45- Longest Subarray with K Sum (HashMap Technique)
46- Longest Subarray with K Sum (Two Pointer Technique)
47- Longest Subarray with K Sum (Dynamic Programming)
48- Longest Subarray with K Sum (Recursion)
49- Longest Subarray with K Sum (Backtracking)
50- Longest Subarray with K Sum (Greedy Approach)
51- Longest Subarray with K Sum (Divide and Conquer)
52- Longest Subarray with K Sum (Bit Manipulation)


*/


void longestSubArrayBetterMethod(vector<int> arr , int K){
    //using hashmap by Striver ( Takeuforward )

    //O(N) time complexity
    //O(N) space complexity

    int n = arr.size();

    unordered_map<int, int> mp; // to store the first occurrence of each prefix sum
    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == K) {
            maxLength = i + 1; // Update maxLength if the prefix sum equals K
        }


        if (mp.find(prefixSum) == mp.end()) {
            mp[prefixSum] = i; // Store the first occurrence of the prefix sum
        }

        if (mp.find(prefixSum - K) != mp.end()) {
            maxLength = max(maxLength, i - mp[prefixSum - K]); // Update maxLength if a subarray with sum K is found
        }
    }
    
    cout << "Longest Subarray Length = " << maxLength << endl;
}

void longestSubArrayBruteBetterMethod(vector<int> arr, int K) {
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
    // longestSubArrayBruteBetterMethod(arr, k);
    longestSubArrayBetterMethod(arr, k);

    return 0;
}