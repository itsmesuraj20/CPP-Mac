// COMPLETE RECURSION PATTERNS GUIDE
// Master these patterns and you'll understand 99% of recursion problems!

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ==========================================
// PATTERN 1: LINEAR RECURSION
// One recursive call per function call
// ==========================================

// 1A: Countdown Pattern
void countdown(int n) {
    if (n <= 0) return;     // Base case
    cout << n << " ";       // Process before recursion
    countdown(n - 1);       // Single recursive call
}

// 1B: Factorial Pattern
int factorial(int n) {
    if (n <= 1) return 1;           // Base case
    return n * factorial(n - 1);    // Process after recursion
}

// 1C: Sum of Array Pattern
int sumArray(vector<int>& arr, int index) {
    if (index >= arr.size()) return 0;              // Base case
    return arr[index] + sumArray(arr, index + 1);   // Current + rest
}

// 1D: Reverse String Pattern
string reverseString(string s, int index = 0) {
    if (index >= s.length()) return "";                         // Base case
    return reverseString(s, index + 1) + s[index];             // Build backwards
}

// ==========================================
// PATTERN 2: BINARY RECURSION
// Two recursive calls per function call
// ==========================================

// 2A: Fibonacci Pattern (Classic Binary Recursion)
int fibonacci(int n) {
    if (n <= 1) return n;                           // Base case
    return fibonacci(n - 1) + fibonacci(n - 2);    // Two calls
}

// 2B: Binary Tree Traversal Pattern
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root) {
    if (!root) return;              // Base case
    inorderTraversal(root->left);   // Left subtree
    cout << root->val << " ";       // Process current
    inorderTraversal(root->right);  // Right subtree
}

// 2C: Tower of Hanoi Pattern
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {                                       // Base case
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);                // Move n-1 to auxiliary
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);                // Move n-1 to destination
}

// ==========================================
// PATTERN 3: MULTIPLE RECURSION
// More than two recursive calls
// ==========================================

// 3A: Generate All Paths Pattern
void generatePaths(int x, int y, int targetX, int targetY, string path) {
    if (x == targetX && y == targetY) {     // Base case
        cout << path << endl;
        return;
    }
    if (x > targetX || y > targetY) return; // Boundary check
    
    generatePaths(x + 1, y, targetX, targetY, path + "R");     // Right
    generatePaths(x, y + 1, targetX, targetY, path + "D");     // Down
}

// 3B: N-ary Tree Traversal Pattern
struct NaryNode {
    int val;
    vector<NaryNode*> children;
    NaryNode(int x) : val(x) {}
};

void traverseNary(NaryNode* root) {
    if (!root) return;                          // Base case
    cout << root->val << " ";                   // Process current
    for (NaryNode* child : root->children) {    // Multiple recursive calls
        traverseNary(child);
    }
}

// ==========================================
// PATTERN 4: DIVIDE & CONQUER
// Divide problem into subproblems, solve, then combine
// ==========================================

// 4A: Merge Sort Pattern
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    
    for (int i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;                      // Base case
    
    int mid = left + (right - left) / 2;            // Divide
    mergeSort(arr, left, mid);                      // Conquer left
    mergeSort(arr, mid + 1, right);                 // Conquer right
    merge(arr, left, mid, right);                   // Combine
}

// 4B: Quick Sort Pattern
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {                               // Base case
        int pi = partition(arr, low, high);         // Divide
        quickSort(arr, low, pi - 1);                // Conquer left
        quickSort(arr, pi + 1, high);               // Conquer right
    }
}

// ==========================================
// PATTERN 5: TAIL RECURSION
// Recursive call is the last operation
// ==========================================

// 5A: Tail Recursive Factorial
int factorialTail(int n, int accumulator = 1) {
    if (n <= 1) return accumulator;                         // Base case
    return factorialTail(n - 1, n * accumulator);          // Tail call
}

// 5B: Tail Recursive Sum
int sumTail(vector<int>& arr, int index, int accumulator = 0) {
    if (index >= arr.size()) return accumulator;           // Base case
    return sumTail(arr, index + 1, accumulator + arr[index]); // Tail call
}

// ==========================================
// PATTERN 6: MUTUAL RECURSION
// Functions call each other recursively
// ==========================================

bool isEven(int n);
bool isOdd(int n);

bool isEven(int n) {
    if (n == 0) return true;    // Base case
    return isOdd(n - 1);        // Call other function
}

bool isOdd(int n) {
    if (n == 0) return false;   // Base case
    return isEven(n - 1);       // Call other function
}

// ==========================================
// PATTERN 7: MEMOIZATION (Dynamic Programming)
// Store results to avoid recomputation
// ==========================================

// 7A: Memoized Fibonacci
int fibMemo(int n, vector<int>& memo) {
    if (n <= 1) return n;                       // Base case
    if (memo[n] != -1) return memo[n];          // Return cached result
    
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo); // Store result
    return memo[n];
}

// 7B: Longest Common Subsequence with Memoization
int lcs(string s1, string s2, int i, int j, vector<vector<int>>& memo) {
    if (i >= s1.length() || j >= s2.length()) return 0;    // Base case
    if (memo[i][j] != -1) return memo[i][j];               // Return cached
    
    if (s1[i] == s2[j]) {
        memo[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, memo);
    } else {
        memo[i][j] = max(lcs(s1, s2, i + 1, j, memo), lcs(s1, s2, i, j + 1, memo));
    }
    return memo[i][j];
}

// ==========================================
// PATTERN 8: BACKTRACKING
// Try all possibilities, undo when stuck
// ==========================================

// 8A: Generate All Permutations
void permutations(vector<int>& nums, int index, vector<vector<int>>& result) {
    if (index == nums.size()) {                 // Base case
        result.push_back(nums);
        return;
    }
    
    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);             // Make choice
        permutations(nums, index + 1, result);  // Recurse
        swap(nums[index], nums[i]);             // Backtrack
    }
}

// 8B: Sudoku Solver Pattern (simplified)
bool solveSudoku(vector<vector<int>>& board, int row, int col) {
    if (row == 9) return true;                  // Base case: solved
    if (col == 9) return solveSudoku(board, row + 1, 0); // Next row
    if (board[row][col] != 0) return solveSudoku(board, row, col + 1); // Skip filled
    
    for (int num = 1; num <= 9; num++) {
        if (isValidSudoku(board, row, col, num)) {
            board[row][col] = num;              // Make choice
            if (solveSudoku(board, row, col + 1)) return true; // Recurse
            board[row][col] = 0;                // Backtrack
        }
    }
    return false;
}

bool isValidSudoku(vector<vector<int>>& board, int row, int col, int num) {
    // Check row, column, and 3x3 box (implementation omitted for brevity)
    return true; // Simplified
}

// ==========================================
// PATTERN 9: TREE RECURSION WITH MULTIPLE RETURNS
// Different recursive calls return different values
// ==========================================

// 9A: Binary Tree Maximum Depth
int maxDepth(TreeNode* root) {
    if (!root) return 0;                        // Base case
    int leftDepth = maxDepth(root->left);       // Left subtree depth
    int rightDepth = maxDepth(root->right);     // Right subtree depth
    return 1 + max(leftDepth, rightDepth);      // Current + max of children
}

// 9B: Binary Search Tree Validation
bool isValidBST(TreeNode* root, long minVal, long maxVal) {
    if (!root) return true;                     // Base case
    if (root->val <= minVal || root->val >= maxVal) return false;
    
    return isValidBST(root->left, minVal, root->val) &&     // Left subtree
           isValidBST(root->right, root->val, maxVal);      // Right subtree
}

// ==========================================
// MAIN FUNCTION WITH EXAMPLES
// ==========================================

int main() {
    cout << "=== RECURSION PATTERNS DEMONSTRATION ===\n\n";
    
    // Pattern 1: Linear Recursion
    cout << "1. LINEAR RECURSION:\n";
    cout << "Countdown: ";
    countdown(5);
    cout << "\nFactorial of 5: " << factorial(5) << "\n\n";
    
    // Pattern 2: Binary Recursion
    cout << "2. BINARY RECURSION:\n";
    cout << "Fibonacci(6): " << fibonacci(6) << "\n";
    cout << "Tower of Hanoi (3 disks):\n";
    towerOfHanoi(3, 'A', 'C', 'B');
    cout << "\n";
    
    // Pattern 3: Multiple Recursion
    cout << "3. MULTIPLE RECURSION:\n";
    cout << "Paths from (0,0) to (2,2):\n";
    generatePaths(0, 0, 2, 2, "");
    cout << "\n";
    
    // Pattern 4: Divide & Conquer
    cout << "4. DIVIDE & CONQUER:\n";
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    mergeSort(arr, 0, arr.size() - 1);
    cout << "\nSorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";
    
    // Pattern 5: Tail Recursion
    cout << "5. TAIL RECURSION:\n";
    cout << "Tail Factorial of 5: " << factorialTail(5) << "\n\n";
    
    // Pattern 6: Mutual Recursion
    cout << "6. MUTUAL RECURSION:\n";
    cout << "Is 4 even? " << (isEven(4) ? "Yes" : "No") << "\n";
    cout << "Is 7 odd? " << (isOdd(7) ? "Yes" : "No") << "\n\n";
    
    // Pattern 7: Memoization
    cout << "7. MEMOIZATION:\n";
    vector<int> memo(10, -1);
    cout << "Memoized Fibonacci(9): " << fibMemo(9, memo) << "\n\n";
    
    cout << "Master these patterns and you'll understand any recursion problem!\n";
    
    return 0;
}

/*
=== RECURSION PATTERNS SUMMARY ===

1. LINEAR RECURSION: One call per function
   - Template: f(n) calls f(n-1) or f(n+1)
   - Examples: Factorial, countdown, array sum

2. BINARY RECURSION: Two calls per function
   - Template: f(n) calls f(n-1) and f(n-2)
   - Examples: Fibonacci, binary tree traversal

3. MULTIPLE RECURSION: Many calls per function
   - Template: f() calls f() multiple times
   - Examples: Generate all paths, n-ary trees

4. DIVIDE & CONQUER: Divide, solve, combine
   - Template: Divide problem → solve subproblems → merge results
   - Examples: Merge sort, quick sort, binary search

5. TAIL RECURSION: Recursive call is last operation
   - Template: return recursive_call()
   - Examples: Tail factorial, accumulator patterns

6. MUTUAL RECURSION: Functions call each other
   - Template: f() calls g(), g() calls f()  
   - Examples: Even/odd check, state machines

7. MEMOIZATION: Store results to avoid recomputation
   - Template: Check cache → compute if needed → store result
   - Examples: Dynamic programming problems

8. BACKTRACKING: Try all possibilities, undo when stuck
   - Template: Try choice → recurse → undo choice
   - Examples: Permutations, N-Queens, Sudoku

9. TREE RECURSION: Process tree-like structures
   - Template: Process current → recurse on children
   - Examples: Tree traversals, tree properties

REMEMBER: Every recursion needs:
1. BASE CASE (when to stop)
2. RECURSIVE CASE (how to break down problem)
3. PROGRESS (getting closer to base case)
*/