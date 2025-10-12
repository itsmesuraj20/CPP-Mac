// /*
// Generate All Permutations: Brute vs Better vs Optimal
// ======================================================
// */

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;


// // ============================================================================
// // APPROACH 1: BRUTE FORCE (Using STL next_permutation)
// // ============================================================================
// /*
// Time Complexity: O(n! * n)
// Space Complexity: O(n! * n) - storing all permutations
// */
// vector<vector<int>> brute_force(vector<int> arr) {
//     vector<vector<int>> result;
//     sort(arr.begin(), arr.end());
    
//     do {
//         result.push_back(arr);
//     } while (next_permutation(arr.begin(), arr.end()));
    
//     return result;
// }

// void print_permutations(const vector<vector<int>>& perms) {
//     for (const auto& perm : perms) {
//         for (int num : perm) {
//             cout << num << " ";
//         }
//         cout << "\n";
//     }
// }


// // ============================================================================
// // APPROACH 2: BETTER (Backtracking with Vector)
// // ============================================================================
// /*
// Time Complexity: O(n! * n)
// Space Complexity: O(n! * n) - storing all permutations
//               + O(n) - recursion stack
// */
// class BetterSolution {
// private:
//     vector<vector<int>> result;
    
//     void backtrack(vector<int>& nums, int start) {
//         // Base case: we've built a complete permutation
//         if (start == nums.size()) {
//             result.push_back(nums);
//             return;
//         }
        
//         // Try swapping each element with the start position
//         for (int i = start; i < nums.size(); i++) {
//             // Swap
//             swap(nums[start], nums[i]);
            
//             // Recurse
//             backtrack(nums, start + 1);
            
//             // Backtrack (undo the swap)
//             swap(nums[start], nums[i]);
//         }
//     }
    
// public:
//     vector<vector<int>> generate(vector<int> arr) {
//         result.clear();
//         backtrack(arr, 0);
//         return result;
//     }
// };


// // ============================================================================
// // APPROACH 3: OPTIMAL (Function Pointer Callback)
// // ============================================================================
// /*
// Time Complexity: O(n!)
// Space Complexity: O(n) - only recursion stack, NOT storing all permutations

// This is OPTIMAL because:
// 1. Doesn't store all permutations in memory
// 2. Processes results on-demand via callback
// 3. User can stop early if needed
// 4. Memory usage is constant O(n) regardless of number of permutations
// */
// class OptimalSolution {
// private:
//     void backtrack(vector<int>& nums, int start, 
//                    function<void(const vector<int>&)> callback) {
//         if (start == nums.size()) {
//             callback(nums);
//             return;
//         }
        
//         for (int i = start; i < nums.size(); i++) {
//             swap(nums[start], nums[i]);
//             backtrack(nums, start + 1, callback);
//             swap(nums[start], nums[i]);
//         }
//     }
    
// public:
//     void generate(vector<int> arr, function<void(const vector<int>&)> callback) {
//         backtrack(arr, 0, callback);
//     }
// };


// // ============================================================================
// // COMPARISON & ANALYSIS
// // ============================================================================

// int main() {
//     vector<int> test = {1, 2, 3};
    
//     cout << "=================================================================\n";
//     cout << "BRUTE FORCE (STL next_permutation)\n";
//     cout << "=================================================================\n";
//     auto brute_result = brute_force(test);
//     print_permutations(brute_result);
//     cout << "\nTotal permutations: " << brute_result.size() << "\n\n";
    
    
//     cout << "=================================================================\n";
//     cout << "BETTER SOLUTION (Backtracking with Vector)\n";
//     cout << "=================================================================\n";
//     BetterSolution better;
//     auto better_result = better.generate(test);
//     print_permutations(better_result);
//     cout << "\nTotal permutations: " << better_result.size() << "\n\n";
    
    
//     cout << "=================================================================\n";
//     cout << "OPTIMAL SOLUTION (Callback-based)\n";
//     cout << "=================================================================\n";
//     OptimalSolution optimal;
//     int count = 0;
//     optimal.generate(test, [&](const vector<int>& perm) {
//         for (int num : perm) {
//             cout << num << " ";
//         }
//         cout << "\n";
//         count++;
//     });
//     cout << "\nTotal permutations: " << count << "\n\n";
    
    
//     cout << "=================================================================\n";
//     cout << "COMPARISON TABLE\n";
//     cout << "=================================================================\n\n";
    
//     cout << "BRUTE FORCE (next_permutation):\n";
//     cout << "  - TC: O(n! * n)\n";
//     cout << "  - SC: O(n! * n)\n";
//     cout << "  - Pros: Simple, uses STL, well-tested\n";
//     cout << "  - Cons: Stores all permutations, less educational\n\n";
    
//     cout << "BETTER SOLUTION (Backtracking):\n";
//     cout << "  - TC: O(n! * n)\n";
//     cout << "  - SC: O(n! * n) + O(n) recursion stack\n";
//     cout << "  - Pros: Shows backtracking logic, educational\n";
//     cout << "  - Cons: Stores all permutations in memory\n\n";
    
//     cout << "OPTIMAL SOLUTION (Callback-based):\n";
//     cout << "  - TC: O(n!)\n";
//     cout << "  - SC: O(n) - only recursion stack\n";
//     cout << "  - Pros: Memory efficient, can stop early\n";
//     cout << "  - Cons: Need callback function, can't access later\n\n";
    
//     cout << "=================================================================\n";
//     cout << "WHEN TO USE EACH:\n";
//     cout << "=================================================================\n\n";
//     cout << "1. BRUTE FORCE: Quick prototyping, small inputs (n <= 8)\n";
//     cout << "2. BETTER: Interview prep, understanding backtracking\n";
//     cout << "3. OPTIMAL: Production code, large inputs, memory constraints\n\n";
    
    
//     // Example: Early stopping with optimal
//     cout << "=================================================================\n";
//     cout << "OPTIMAL - Early Stopping Example (first 6 permutations):\n";
//     cout << "=================================================================\n";
//     OptimalSolution optimal2;
//     int stop_count = 0;
//     optimal2.generate(test, [&](const vector<int>& perm) {
//         if (stop_count >= 6) return;
//         for (int num : perm) {
//             cout << num << " ";
//         }
//         cout << "\n";
//         stop_count++;
//     });
//     cout << "... (stopped early)\n";
    
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;

void generatePermutation(int index , vector<int> &nums, vector<vector<int>> &result ){
    int n = nums.size();
    
    if(index == n){
        result.push_back(nums);
        return ;
    }


    for(int i = index ; i<n ; i++){
        swap(nums[index] , nums[i]);
        generatePermutation(index + 1, nums,result);
        swap(nums[index] , nums[i]);
    }
}


int main(){

    vector<int> nums = { 1,2,3};

    vector<vector<int>> allPermutations;
    generatePermutation(0,nums,allPermutations);

    for(auto i : allPermutations){
        for(int num : i){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}