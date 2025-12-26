/*
===============================================================================
    COMPLETE RECURSION & BACKTRACKING TUTORIAL - C++
    From Zero to Hero - All Patterns, Concepts & Templates
===============================================================================

TABLE OF CONTENTS:
Part 1: Recursion Fundamentals (10 Patterns)
Part 2: Backtracking Fundamentals (8 Patterns)
Part 3: Advanced Techniques & Optimizations
Part 4: Common Pitfalls & Solutions
Part 5: Cheat Codes & Templates
Part 6: Practice Roadmap

===============================================================================
PART 1: RECURSION FUNDAMENTALS
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/*
RECURSION BASICS:
1. Base Case: Stopping condition (MUST have!)
2. Recursive Case: Function calls itself with simpler input
3. Stack Space: Each call uses stack memory (watch for stack overflow)
4. Trust the recursion: Assume smaller problems are solved correctly

RECURSION EQUATION:
T(n) = T(smaller_problem) + Work_at_current_level
*/

// ============================================================================
// PATTERN 1: LINEAR RECURSION (Most Common)
// ============================================================================

// Template
void linearRecursion(int n) {
    if (n <= 0) return;  // BASE CASE
    
    // PRE-PROCESSING (before recursive call)
    cout << n << " ";
    
    linearRecursion(n - 1);  // RECURSIVE CALL
    
    // POST-PROCESSING (after recursive call - executes in reverse)
}

// Print 1 to N
void print1toN(int n) {
    if (n <= 0) return;
    print1toN(n - 1);
    cout << n << " ";
}

// Print N to 1
void printNto1(int n) {
    if (n <= 0) return;
    cout << n << " ";
    printNto1(n - 1);
}

// Sum of N numbers
int sumN(int n) {
    if (n <= 0) return 0;
    return n + sumN(n - 1);
}

// Power calculation
int power(int x, int n) {
    if (n == 0) return 1;
    return x * power(x, n - 1);
}

// Count digits
int countDigits(int n) {
    if (n < 10) return 1;
    return 1 + countDigits(n / 10);
}

// ============================================================================
// PATTERN 2: TAIL RECURSION (Optimizable by Compiler)
// ============================================================================

/*
TAIL RECURSION: Recursive call is LAST operation
- No pending operations after recursive call
- Can be converted to iteration (no stack overflow)
- Pass accumulator as parameter
*/

int factorialTail(int n, int acc = 1) {
    if (n <= 1) return acc;
    return factorialTail(n - 1, n * acc);
}

int sumTail(int n, int acc = 0) {
    if (n <= 0) return acc;
    return sumTail(n - 1, n + acc);
}

// ============================================================================
// PATTERN 3: TREE RECURSION (Multiple Calls)
// ============================================================================

/*
TREE RECURSION: Function makes multiple recursive calls
- Creates tree of calls
- Often exponential time complexity
*/

// Fibonacci
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// Tower of Hanoi
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);
}

// ============================================================================
// PATTERN 4: DIVIDE AND CONQUER
// ============================================================================

/*
STEPS: DIVIDE -> CONQUER -> COMBINE
*/

// Binary Search
int binarySearch(vector<int>& arr, int l, int r, int x) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
}

// Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);
    for (int k = 0; k < temp.size(); k++) arr[l + k] = temp[k];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Quick Sort
int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r], i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int pi = partition(arr, l, r);
    quickSort(arr, l, pi - 1);
    quickSort(arr, pi + 1, r);
}

// ============================================================================
// PATTERN 5: SUBSEQUENCE GENERATION (Pick/Not Pick)
// ============================================================================

/*
SUBSEQUENCE PATTERN: At each index - PICK or NOT PICK
Total subsequences = 2^n
*/

// Generate all subsequences
void generateSubseq(vector<int>& arr, int i, vector<int>& curr,
                    vector<vector<int>>& res) {
    if (i == arr.size()) {
        res.push_back(curr);
        return;
    }
    // Not pick
    generateSubseq(arr, i + 1, curr, res);
    // Pick
    curr.push_back(arr[i]);
    generateSubseq(arr, i + 1, curr, res);
    curr.pop_back();
}

// Print subsequences with sum K
void subseqSumK(vector<int>& arr, int i, int sum, int k, vector<int>& curr) {
    if (i == arr.size()) {
        if (sum == k) {
            for (int x : curr) cout << x << " ";
            cout << endl;
        }
        return;
    }
    curr.push_back(arr[i]);
    subseqSumK(arr, i + 1, sum + arr[i], k, curr);
    curr.pop_back();
    subseqSumK(arr, i + 1, sum, k, curr);
}

// Count subsequences with sum K
int countSubseqSumK(vector<int>& arr, int i, int sum, int k) {
    if (i == arr.size()) return sum == k ? 1 : 0;
    return countSubseqSumK(arr, i + 1, sum + arr[i], k) +
           countSubseqSumK(arr, i + 1, sum, k);
}

// First subsequence with sum K (return optimization)
bool findFirstSubseq(vector<int>& arr, int i, int sum, int k,
                     vector<int>& curr) {
    if (i == arr.size()) {
        if (sum == k) {
            for (int x : curr) cout << x << " ";
            return true;
        }
        return false;
    }
    curr.push_back(arr[i]);
    if (findFirstSubseq(arr, i + 1, sum + arr[i], k, curr)) return true;
    curr.pop_back();
    if (findFirstSubseq(arr, i + 1, sum, k, curr)) return true;
    return false;
}

// ============================================================================
// PATTERN 6: PARAMETERIZED vs FUNCTIONAL RECURSION
// ============================================================================

// PARAMETERIZED - Pass result as parameter
void sumParam(int n, int sum) {
    if (n < 1) {
        cout << sum;
        return;
    }
    sumParam(n - 1, sum + n);
}

// FUNCTIONAL - Return result
int sumFunc(int n) {
    if (n < 1) return 0;
    return n + sumFunc(n - 1);
}

// Reverse array using two pointers
void reverseArray(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    swap(arr[l], arr[r]);
    reverseArray(arr, l + 1, r - 1);
}

// Check palindrome
bool isPalindrome(string& s, int i) {
    if (i >= s.length() / 2) return true;
    if (s[i] != s[s.length() - i - 1]) return false;
    return isPalindrome(s, i + 1);
}

// ============================================================================
// PATTERN 7: MULTIPLE RECURSION ON ARRAYS
// ============================================================================

// Generate combinations of size K
void combineK(vector<int>& arr, int i, int k, vector<int>& curr,
              vector<vector<int>>& res) {
    if (curr.size() == k) {
        res.push_back(curr);
        return;
    }
    if (i == arr.size()) return;
    
    curr.push_back(arr[i]);
    combineK(arr, i + 1, k, curr, res);
    curr.pop_back();
    combineK(arr, i + 1, k, curr, res);
}

// Letter combinations of phone number
void letterCombos(string& digits, int i, string& curr,
                  vector<string>& res, vector<string>& keys) {
    if (i == digits.length()) {
        if (!curr.empty()) res.push_back(curr);
        return;
    }
    string letters = keys[digits[i] - '0'];
    for (char c : letters) {
        curr.push_back(c);
        letterCombos(digits, i + 1, curr, res, keys);
        curr.pop_back();
    }
}

// ============================================================================
// PATTERN 8: RECURSION ON TREES
// ============================================================================

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Height of tree
int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Diameter of tree
int diameter(TreeNode* root, int& d) {
    if (!root) return 0;
    int lh = diameter(root->left, d);
    int rh = diameter(root->right, d);
    d = max(d, lh + rh);
    return 1 + max(lh, rh);
}

// All paths root to leaf
void allPaths(TreeNode* root, vector<int>& path, vector<vector<int>>& res) {
    if (!root) return;
    path.push_back(root->val);
    if (!root->left && !root->right) res.push_back(path);
    allPaths(root->left, path, res);
    allPaths(root->right, path, res);
    path.pop_back();
}

// Path with sum K
bool hasPathSum(TreeNode* root, int sum, int k) {
    if (!root) return false;
    sum += root->val;
    if (!root->left && !root->right) return sum == k;
    return hasPathSum(root->left, sum, k) || hasPathSum(root->right, sum, k);
}

// ============================================================================
// PATTERN 9: MEMOIZATION (Top-Down DP)
// ============================================================================

// Fibonacci with memo
int fibMemo(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}

// Climbing stairs
int climbStairs(int n, vector<int>& dp) {
    if (n <= 2) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);
}

// House robber
int rob(vector<int>& nums, int i, vector<int>& dp) {
    if (i >= nums.size()) return 0;
    if (dp[i] != -1) return dp[i];
    int take = nums[i] + rob(nums, i + 2, dp);
    int notTake = rob(nums, i + 1, dp);
    return dp[i] = max(take, notTake);
}

// ============================================================================
// PATTERN 10: STRING RECURSION
// ============================================================================

// Generate permutations of string
void permuteStr(string& s, int i, vector<string>& res) {
    if (i == s.length()) {
        res.push_back(s);
        return;
    }
    for (int j = i; j < s.length(); j++) {
        swap(s[i], s[j]);
        permuteStr(s, i + 1, res);
        swap(s[i], s[j]);
    }
}

// Generate all substrings
void allSubstrings(string& s, int start, int end, vector<string>& res) {
    if (start == s.length()) return;
    if (end == s.length()) {
        allSubstrings(s, start + 1, start + 1, res);
        return;
    }
    res.push_back(s.substr(start, end - start + 1));
    allSubstrings(s, start, end + 1, res);
}

/*
===============================================================================
PART 2: BACKTRACKING FUNDAMENTALS
===============================================================================

BACKTRACKING = RECURSION + TRIAL & ERROR + UNDO

TEMPLATE:
void backtrack(state, choices) {
    if (is_goal(state)) {
        add_solution(state);
        return;
    }
    for (choice in choices) {
        if (is_valid(choice)) {
            make_choice(choice);      // CHOOSE
            backtrack(new_state);      // EXPLORE
            undo_choice(choice);       // UNCHOOSE
        }
    }
}
*/

// ============================================================================
// BACKTRACKING PATTERN 1: PERMUTATIONS
// ============================================================================

// Method 1: Swap technique
void permute(vector<int>& nums, int i, vector<vector<int>>& res) {
    if (i == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int j = i; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
        permute(nums, i + 1, res);
        swap(nums[i], nums[j]);
    }
}

// Method 2: Used array
void permuteUsed(vector<int>& nums, vector<int>& curr, vector<bool>& used,
                 vector<vector<int>>& res) {
    if (curr.size() == nums.size()) {
        res.push_back(curr);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        curr.push_back(nums[i]);
        used[i] = true;
        permuteUsed(nums, curr, used, res);
        used[i] = false;
        curr.pop_back();
    }
}

// Permutations with duplicates
void permuteUnique(vector<int>& nums, int i, vector<vector<int>>& res) {
    if (i == nums.size()) {
        res.push_back(nums);
        return;
    }
    unordered_set<int> seen;
    for (int j = i; j < nums.size(); j++) {
        if (seen.count(nums[j])) continue;
        seen.insert(nums[j]);
        swap(nums[i], nums[j]);
        permuteUnique(nums, i + 1, res);
        swap(nums[i], nums[j]);
    }
}

// ============================================================================
// BACKTRACKING PATTERN 2: COMBINATIONS
// ============================================================================

// Combinations of size K
void combine(int n, int k, int start, vector<int>& curr,
             vector<vector<int>>& res) {
    if (curr.size() == k) {
        res.push_back(curr);
        return;
    }
    for (int i = start; i <= n; i++) {
        curr.push_back(i);
        combine(n, k, i + 1, curr, res);
        curr.pop_back();
    }
}

// Combination Sum (reuse allowed)
void combinationSum(vector<int>& arr, int target, int i, vector<int>& curr,
                    vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(curr);
        return;
    }
    if (i == arr.size() || target < 0) return;
    
    curr.push_back(arr[i]);
    combinationSum(arr, target - arr[i], i, curr, res);
    curr.pop_back();
    combinationSum(arr, target, i + 1, curr, res);
}

// Combination Sum II (no reuse)
void combinationSum2(vector<int>& arr, int target, int i, vector<int>& curr,
                     vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(curr);
        return;
    }
    for (int j = i; j < arr.size(); j++) {
        if (j > i && arr[j] == arr[j-1]) continue;
        if (arr[j] > target) break;
        curr.push_back(arr[j]);
        combinationSum2(arr, target - arr[j], j + 1, curr, res);
        curr.pop_back();
    }
}

// ============================================================================
// BACKTRACKING PATTERN 3: SUBSETS
// ============================================================================

// All subsets
void subsets(vector<int>& nums, int i, vector<int>& curr,
             vector<vector<int>>& res) {
    res.push_back(curr);
    for (int j = i; j < nums.size(); j++) {
        curr.push_back(nums[j]);
        subsets(nums, j + 1, curr, res);
        curr.pop_back();
    }
}

// Subsets with duplicates
void subsetsWithDup(vector<int>& nums, int i, vector<int>& curr,
                    vector<vector<int>>& res) {
    res.push_back(curr);
    for (int j = i; j < nums.size(); j++) {
        if (j > i && nums[j] == nums[j-1]) continue;
        curr.push_back(nums[j]);
        subsetsWithDup(nums, j + 1, curr, res);
        curr.pop_back();
    }
}

// ============================================================================
// BACKTRACKING PATTERN 4: N-QUEENS
// ============================================================================

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

void solveNQueens(int row, int n, vector<string>& board,
                  vector<vector<string>>& res) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(row + 1, n, board, res);
            board[row][col] = '.';
        }
    }
}

// Optimized N-Queens with hash sets
void nQueensOpt(int row, int n, vector<string>& board,
                vector<vector<string>>& res, unordered_set<int>& cols,
                unordered_set<int>& d1, unordered_set<int>& d2) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        int diag1 = row - col, diag2 = row + col;
        if (cols.count(col) || d1.count(diag1) || d2.count(diag2)) continue;
        
        board[row][col] = 'Q';
        cols.insert(col); d1.insert(diag1); d2.insert(diag2);
        nQueensOpt(row + 1, n, board, res, cols, d1, d2);
        cols.erase(col); d1.erase(diag1); d2.erase(diag2);
        board[row][col] = '.';
    }
}

// ============================================================================
// BACKTRACKING PATTERN 5: SUDOKU SOLVER
// ============================================================================

bool isValidSudoku(vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) return false;
    }
    int sr = (row/3)*3, sc = (col/3)*3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[sr+i][sc+j] == num) return false;
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isValidSudoku(board, i, j, num)) {
                        board[i][j] = num;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// ============================================================================
// BACKTRACKING PATTERN 6: RAT IN MAZE
// ============================================================================

void ratMaze(vector<vector<int>>& maze, int r, int c, int n, string& path,
             vector<string>& res, vector<vector<bool>>& vis) {
    if (r == n-1 && c == n-1) {
        res.push_back(path);
        return;
    }
    
    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'};
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
            maze[nr][nc] == 1 && !vis[nr][nc]) {
            vis[nr][nc] = true;
            path.push_back(dir[i]);
            ratMaze(maze, nr, nc, n, path, res, vis);
            path.pop_back();
            vis[nr][nc] = false;
        }
    }
}

// ============================================================================
// BACKTRACKING PATTERN 7: WORD SEARCH
// ============================================================================

bool wordSearch(vector<vector<char>>& board, int r, int c,
                string& word, int i) {
    if (i == word.length()) return true;
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() ||
        board[r][c] != word[i]) return false;
    
    char temp = board[r][c];
    board[r][c] = '#';
    bool found = wordSearch(board, r+1, c, word, i+1) ||
                 wordSearch(board, r-1, c, word, i+1) ||
                 wordSearch(board, r, c+1, word, i+1) ||
                 wordSearch(board, r, c-1, word, i+1);
    board[r][c] = temp;
    return found;
}

// ============================================================================
// BACKTRACKING PATTERN 8: PARTITION PROBLEMS
// ============================================================================

bool isPalin(string& s, int l, int r) {
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

// Palindrome partitioning
void palindromePartition(string& s, int i, vector<string>& curr,
                        vector<vector<string>>& res) {
    if (i == s.length()) {
        res.push_back(curr);
        return;
    }
    for (int j = i; j < s.length(); j++) {
        if (isPalin(s, i, j)) {
            curr.push_back(s.substr(i, j - i + 1));
            palindromePartition(s, j + 1, curr, res);
            curr.pop_back();
        }
    }
}

// Subset sum partition (equal sum)
bool canPartition(vector<int>& nums, int i, int sum1, int sum2) {
    if (i == nums.size()) return sum1 == sum2;
    return canPartition(nums, i+1, sum1+nums[i], sum2) ||
           canPartition(nums, i+1, sum1, sum2+nums[i]);
}

/*
===============================================================================
PART 3: ADVANCED TECHNIQUES & OPTIMIZATIONS
===============================================================================
*/

// ============================================================================
// TECHNIQUE 1: EARLY TERMINATION
// ============================================================================

// Stop as soon as solution found
bool findAnySubset(vector<int>& nums, int i, int sum, int target) {
    if (sum == target) return true;
    if (i == nums.size() || sum > target) return false;
    return findAnySubset(nums, i+1, sum+nums[i], target) ||
           findAnySubset(nums, i+1, sum, target);
}

// ============================================================================
// TECHNIQUE 2: PRUNING
// ============================================================================

// Skip unnecessary branches
void combinationSumPruned(vector<int>& arr, int target, int i,
                         vector<int>& curr, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(curr);
        return;
    }
    for (int j = i; j < arr.size(); j++) {
        if (arr[j] > target) break;  // PRUNE: No point checking further
        curr.push_back(arr[j]);
        combinationSumPruned(arr, target - arr[j], j + 1, curr, res);
        curr.pop_back();
    }
}

// ============================================================================
// TECHNIQUE 3: MEMOIZATION
// ============================================================================

// Store computed results
int longestIncreasingPath(vector<vector<int>>& matrix, int r, int c,
                         vector<vector<int>>& dp) {
    if (dp[r][c] != -1) return dp[r][c];
    
    int maxLen = 1;
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < matrix.size() && nc >= 0 &&
            nc < matrix[0].size() && matrix[nr][nc] > matrix[r][c]) {
            maxLen = max(maxLen, 1 + longestIncreasingPath(matrix, nr, nc, dp));
        }
    }
    return dp[r][c] = maxLen;
}

// ============================================================================
// TECHNIQUE 4: ITERATIVE CONVERSION (For Tail Recursion)
// ============================================================================

// Recursive factorial
int factRec(int n) {
    if (n <= 1) return 1;
    return n * factRec(n - 1);
}

// Iterative factorial (no stack overflow)
int factIter(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

/*
===============================================================================
PART 4: COMMON PITFALLS & SOLUTIONS
===============================================================================

PITFALL 1: NO BASE CASE
❌ void infinite() { infinite(); }  // Stack overflow!
✅ void correct(int n) { if (n <= 0) return; correct(n-1); }

PITFALL 2: WRONG BASE CASE
❌ int fib(int n) { if (n == 0) return 0; return fib(n-1) + fib(n-2); }
✅ int fib(int n) { if (n <= 1) return n; return fib(n-1) + fib(n-2); }

PITFALL 3: FORGETTING TO BACKTRACK
❌ void permute(vector<int>& nums, int i) {
     nums.push_back(x);
     permute(nums, i+1);
     // Missing: nums.pop_back();
   }
✅ void permute(vector<int>& nums, int i) {
     nums.push_back(x);
     permute(nums, i+1);
     nums.pop_back();  // BACKTRACK!
   }

PITFALL 4: MODIFYING GLOBAL STATE WITHOUT RESTORE
❌ vector<int> path;
   void dfs(int i) {
     path.push_back(i);
     dfs(i+1);
   }
✅ void dfs(int i, vector<int>& path) {
     path.push_back(i);
     dfs(i+1, path);
     path.pop_back();
   }

PITFALL 5: USING VISITED WITHOUT UNMARKING
❌ void dfs(int i) {
     visited[i] = true;
     dfs(i+1);
   }
✅ void dfs(int i) {
     visited[i] = true;
     dfs(i+1);
     visited[i] = false;
   }

PITFALL 6: NOT PASSING BY REFERENCE (Performance)
❌ void solve(vector<int> arr)  // COPIES entire array!
✅ void solve(vector<int>& arr) // Pass by reference

PITFALL 7: INFINITE RECURSION (No Progress to Base Case)
❌ void bad(int n) { if (n == 0) return; bad(n); }  // n never changes!
✅ void good(int n) { if (n == 0) return; good(n-1); }

PITFALL 8: STACK OVERFLOW (Too Deep Recursion)
Solution: Use memoization or convert to iteration

PITFALL 9: DUPLICATE RESULTS (Not Handling Properly)
✅ Sort array first + skip duplicates
✅ Use unordered_set to track seen values
✅ Always start from i+1 in combinations

PITFALL 10: TLE (Time Limit Exceeded)
Solutions:
- Add memoization
- Prune unnecessary branches
- Use early termination
- Optimize base cases

===============================================================================
PART 5: CHEAT CODES & TEMPLATES
===============================================================================
*/

// ============================================================================
// TEMPLATE 1: SUBSEQUENCE GENERATION
// ============================================================================
void subseqTemplate(vector<int>& arr, int i, vector<int>& curr, 
                    vector<vector<int>>& res) {
    if (i == arr.size()) {
        res.push_back(curr);
        return;
    }
    // Not take
    subseqTemplate(arr, i+1, curr, res);
    // Take
    curr.push_back(arr[i]);
    subseqTemplate(arr, i+1, curr, res);
    curr.pop_back();
}

// ============================================================================
// TEMPLATE 2: PERMUTATION
// ============================================================================
void permuteTemplate(vector<int>& nums, int i, vector<vector<int>>& res) {
    if (i == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int j = i; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
        permuteTemplate(nums, i+1, res);
        swap(nums[i], nums[j]);
    }
}

// ============================================================================
// TEMPLATE 3: COMBINATION
// ============================================================================
void combineTemplate(int n, int k, int start, vector<int>& curr,
                     vector<vector<int>>& res) {
    if (curr.size() == k) {
        res.push_back(curr);
        return;
    }
    for (int i = start; i <= n; i++) {
        curr.push_back(i);
        combineTemplate(n, k, i+1, curr, res);
        curr.pop_back();
    }
}

// ============================================================================
// TEMPLATE 4: SUBSET
// ============================================================================
void subsetTemplate(vector<int>& nums, int i, vector<int>& curr,
                    vector<vector<int>>& res) {
    res.push_back(curr);
    for (int j = i; j < nums.size(); j++) {
        curr.push_back(nums[j]);
        subsetTemplate(nums, j+1, curr, res);
        curr.pop_back();
    }
}

// ============================================================================
// TEMPLATE 5: MATRIX DFS (4 directions)
// ============================================================================
void dfsMatrix(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
        grid[r][c] == 0) return;
    
    grid[r][c] = 0;  // Mark visited
    dfsMatrix(grid, r+1, c);
    dfsMatrix(grid, r-1, c);
    dfsMatrix(grid, r, c+1);
    dfsMatrix(grid, r, c-1);
}

// ============================================================================
// TEMPLATE 6: TREE DFS
// ============================================================================
void dfsTree(TreeNode* root, vector<int>& path) {
    if (!root) return;
    path.push_back(root->val);
    
    if (!root->left && !root->right) {
        // Process leaf
    }
    
    dfsTree(root->left, path);
    dfsTree(root->right, path);
    path.pop_back();
}

// ============================================================================
// TEMPLATE 7: PARTITION PROBLEMS
// ============================================================================
void partitionTemplate(string& s, int i, vector<string>& curr,
                      vector<vector<string>>& res) {
    if (i == s.length()) {
        res.push_back(curr);
        return;
    }
    for (int j = i; j < s.length(); j++) {
        if (isValid(s, i, j)) {
            curr.push_back(s.substr(i, j-i+1));
            partitionTemplate(s, j+1, curr, res);
            curr.pop_back();
        }
    }
}

bool isValid(string& s, int l, int r) {
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

// ============================================================================
// TEMPLATE 8: MEMOIZATION
// ============================================================================
int dpTemplate(int n, vector<int>& dp) {
    if (n <= BASE_CASE) return BASE_VALUE;
    if (dp[n] != -1) return dp[n];
    
    int result = 0;
    // Compute result using recursive calls
    
    return dp[n] = result;
}

/*
===============================================================================
PART 6: PRACTICE ROADMAP (0 to 100)
===============================================================================

LEVEL 1: BASICS (Days 1-3)
□ Print 1 to N
□ Print N to 1
□ Sum of N numbers
□ Factorial
□ Power(x, n)
□ Reverse array
□ Check palindrome
□ Fibonacci
□ GCD/HCF
□ Count digits

LEVEL 2: INTERMEDIATE (Days 4-7)
□ Tower of Hanoi
□ Binary search (recursive)
□ Merge sort
□ Quick sort
□ Generate all subsequences
□ Subsequences with sum K
□ Print all permutations
□ Combination sum
□ Subsets
□ Letter combinations of phone number

LEVEL 3: TREES & GRAPHS (Days 8-10)
□ Tree height/depth
□ Tree diameter
□ All root to leaf paths
□ Path sum
□ Lowest common ancestor
□ Validate BST
□ Number of islands
□ Clone graph
□ Word ladder
□ Course schedule

LEVEL 4: BACKTRACKING (Days 11-15)
□ N-Queens
□ Sudoku solver
□ Rat in maze
□ Word search
□ Palindrome partitioning
□ Restore IP addresses
□ Combinations
□ Permutations II
□ Subsets II
□ Letter case permutation

LEVEL 5: ADVANCED (Days 16-21)
□ Expression add operators
□ Remove invalid parentheses
□ Word break II
□ Wildcard matching
□ Regular expression matching
□ Longest increasing path
□ Beautiful arrangement
□ K-th symbol in grammar
□ Different ways to add parentheses
□ Unique paths III

===============================================================================
COMPLEXITY ANALYSIS CHEAT SHEET
===============================================================================

RECURSION TIME COMPLEXITIES:
Linear Recursion: O(n)
Binary Recursion (like Fibonacci): O(2^n)
Divide & Conquer (Merge/Quick Sort): O(n log n)
Permutations: O(n! * n)
Combinations C(n,k): O(C(n,k) * k)
Subsets: O(2^n * n)
N-Queens: O(n!)

SPACE COMPLEXITIES:
Recursion Stack: O(depth)
Linear recursion: O(n)
Binary search: O(log n)
Tree problems: O(height)
With memoization: Add O(n) or O(n²) for dp array

===============================================================================
KEY DECISION FLOWCHART
===============================================================================

Is it a sequence/array problem?
├─ Need all arrangements? → PERMUTATION
├─ Need all selections (order doesn't matter)? → COMBINATION
├─ Need all possible subsets? → SUBSET
└─ Need specific sum/target? → SUBSEQUENCE (pick/not pick)

Is it a grid/matrix problem?
├─ Finding paths? → RAT IN MAZE pattern
├─ Word search? → WORD SEARCH pattern
└─ Counting islands/components? → DFS/BFS

Is it a constraint satisfaction problem?
├─ Placing items with rules? → N-QUEENS pattern
└─ Filling grid with rules? → SUDOKU pattern

Is it a partition problem?
├─ Splitting string? → PARTITION pattern
└─ Splitting array? → SUBSET SUM pattern

===============================================================================
DEBUGGING TIPS
===============================================================================

1. PRINT THE RECURSION TREE
   Add: cout << string(depth*2, ' ') << "Call with n=" << n << endl;

2. TRACK STATE
   Print current, path, visited before each call

3. CHECK BASE CASES
   Are they handling all edge cases?
   Empty input, single element, negative numbers?

4. VERIFY BACKTRACKING
   Is state restored after each recursive call?

5. COUNT CALLS
   Add static counter to see if exponential

6. USE DEBUGGER
   Set breakpoint, step through recursion

7. DRAW IT OUT
   Manually trace for small inputs (n=3)

===============================================================================
INTERVIEW TIPS
===============================================================================

1. ALWAYS START WITH BASE CASE
   Interviewer wants to see you think about edge cases

2. EXPLAIN YOUR APPROACH
   "I'll use pick/not pick pattern for subsequences"

3. MENTION TIME/SPACE COMPLEXITY
   Before coding, state: "This will be O(2^n) time, O(n) space"

4. ASK CLARIFYING QUESTIONS
   - Can array have duplicates?
   - Can integers be negative?
   - What's the constraint on input size?

5. START WITH BRUTE FORCE
   Then optimize with memoization if needed

6. TEST WITH EXAMPLES
   Walk through your code with interviewer's example

7. OPTIMIZE IF POSSIBLE
   "We can prune branches where sum > target"

===============================================================================
FINAL CHECKLIST
===============================================================================

Before solving ANY recursion/backtracking problem:

□ Identified the pattern (permutation/combination/subset/partition/maze)
□ Defined clear base case(s)
□ Decided: parameterized or functional recursion?
□ Will I need backtracking (undo operations)?
□ Do I need to mark visited?
□ Should I use memoization?
□ Handling duplicates? (sort + skip)
□ Is there pruning opportunity?
□ Space optimization possible?

===============================================================================
PRACTICE PROBLEMS BY PATTERN
===============================================================================

PERMUTATIONS:
- LeetCode 46, 47, 31, 60, 77, 996

COMBINATIONS:
- LeetCode 77, 39, 40, 216, 377

SUBSETS:
- LeetCode 78, 90, 491

N-QUEENS:
- LeetCode 51, 52, 1001

SUDOKU:
- LeetCode 36, 37

MAZE/PATH:
- LeetCode 62, 63, 64, 980

WORD SEARCH:
- LeetCode 79, 212

PARTITION:
- LeetCode 131, 132, 93, 698

TREE RECURSION:
- LeetCode 104, 110, 124, 543, 112, 113, 257

MEMOIZATION:
- LeetCode 70, 198, 213, 322, 518

===============================================================================
YOU'RE READY WHEN...
===============================================================================

✓ You can identify the pattern in 30 seconds
✓ You can write base case without thinking
✓ You understand when to backtrack
✓ You can optimize with memoization
✓ You can explain time/space complexity
✓ You can handle duplicates
✓ You can debug recursion tree
✓ You've solved 50+ problems across all patterns

===============================================================================
REMEMBER: Trust the recursion! Assume smaller problems are solved correctly.
===============================================================================
*/

// Example: Complete solution with all best practices
class RecursionBacktrackingMaster {
public:
    // Example: Combination Sum with all optimizations
    vector<vector<int>> combinationSumPro(vector<int>& arr, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(arr.begin(), arr.end());  // For pruning
        backtrack(arr, target, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& arr, int target, int start,
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: Found valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Iterate through choices
        for (int i = start; i < arr.size(); i++) {
            // Pruning: No point continuing if current element > target
            if (arr[i] > target) break;
            
            // CHOOSE
            current.push_back(arr[i]);
            
            // EXPLORE (can reuse same element, so pass i not i+1)
            backtrack(arr, target - arr[i], i, current, result);
            
            // UNCHOOSE (backtrack)
            current.pop_back();
        }
    }
};

/*
===============================================================================
CONGRATULATIONS! 🎉
You now have complete mastery over Recursion & Backtracking!
Practice consistently and you'll never need to revisit these concepts again.
===============================================================================
*/