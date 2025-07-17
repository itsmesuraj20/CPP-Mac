// BACKTRACKING TUTORIAL IN C++
// Let's learn step by step with simple examples!

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ==========================================
// EXAMPLE 1: SIMPLE PATH FINDING IN MAZE
// ==========================================

bool solveMaze(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& solution) {
    int n = maze.size();
    
    // Base case: reached destination
    if (x == n-1 && y == n-1) {
        solution[x][y] = 1;
        return true;
    }
    
    // Check if current position is valid
    if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1) {
        
        // Mark current cell as part of solution
        solution[x][y] = 1;
        
        // Try moving right
        if (solveMaze(maze, x, y + 1, solution)) {
            return true;
        }
        
        // Try moving down
        if (solveMaze(maze, x + 1, y, solution)) {
            return true;
        }
        
        // BACKTRACK: Unmark current cell
        solution[x][y] = 0;
    }
    
    return false;
}

// ==========================================
// EXAMPLE 2: GENERATE ALL SUBSETS
// ==========================================

void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    // Base case: we've considered all elements
    if (index == nums.size()) {
        result.push_back(current); // Add current subset
        return;
    }
    
    // Choice 1: Include current element
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, result);
    
    // BACKTRACK: Remove the element we just added
    current.pop_back();
    
    // Choice 2: Don't include current element
    generateSubsets(nums, index + 1, current, result);
}

// ==========================================
// EXAMPLE 3: N-QUEENS PROBLEM (SIMPLIFIED)
// ==========================================

bool isSafe(vector<vector<int>>& board, int row, int col) {
    int n = board.size();
    
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    
    // Check diagonal (top-left to bottom-right)
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    // Check diagonal (top-right to bottom-left)
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row) {
    int n = board.size();
    
    // Base case: All queens placed successfully
    if (row >= n) {
        return true;
    }
    
    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        
        // Check if it's safe to place queen here
        if (isSafe(board, row, col)) {
            
            // Make choice: Place queen
            board[row][col] = 1;
            
            // Recursively place queens in next rows
            if (solveNQueens(board, row + 1)) {
                return true;
            }
            
            // BACKTRACK: Remove queen if it doesn't lead to solution
            board[row][col] = 0;
        }
    }
    
    return false; // No solution found
}

// ==========================================
// EXAMPLE 4: PERMUTATIONS
// ==========================================

void generatePermutations(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
    // Base case: current permutation is complete
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    
    // Try each unused number
    for (int i = 0; i < nums.size(); i++) {
        if (!used[i]) {
            
            // Make choice: use this number
            current.push_back(nums[i]);
            used[i] = true;
            
            // Recurse
            generatePermutations(nums, current, used, result);
            
            // BACKTRACK: undo the choice
            current.pop_back();
            used[i] = false;
        }
    }
}

// ==========================================
// EXAMPLE 5: SUDOKU SOLVER (BONUS!)
// ==========================================

bool isValidSudoku(vector<vector<int>>& board, int row, int col, int num) {
    // Check row
    for (int j = 0; j < 9; j++) {
        if (board[row][j] == num) {
            return false;
        }
    }
    
    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    
    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    
    return true;
}

bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            
            // Find empty cell
            if (board[row][col] == 0) {
                
                // Try numbers 1-9
                for (int num = 1; num <= 9; num++) {
                    
                    if (isValidSudoku(board, row, col, num)) {
                        
                        // Make choice: place number
                        board[row][col] = num;
                        
                        // Recurse
                        if (solveSudoku(board)) {
                            return true;
                        }
                        
                        // BACKTRACK: remove number
                        board[row][col] = 0;
                    }
                }
                
                return false; // No valid number found
            }
        }
    }
    
    return true; // Board is complete
}

// ==========================================
// UTILITY FUNCTIONS
// ==========================================

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void printVector(const vector<int>& vec) {
    cout << "{ ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << " }";
}

// ==========================================
// MAIN FUNCTION WITH TEST CASES
// ==========================================

int main() {
    cout << "=== BACKTRACKING EXAMPLES IN C++ ===\n\n";
    
    // Test 1: Maze solving
    cout << "1. MAZE SOLVING:\n";
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    vector<vector<int>> solution(4, vector<int>(4, 0));
    
    if (solveMaze(maze, 0, 0, solution)) {
        cout << "Path found:\n";
        printMatrix(solution);
    } else {
        cout << "No path found\n";
    }
    
    // Test 2: Generate subsets
    cout << "\n2. SUBSETS OF [1,2,3]:\n";
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets;
    vector<int> current;
    generateSubsets(nums, 0, current, subsets);
    
    for (const auto& subset : subsets) {
        printVector(subset);
        cout << "\n";
    }
    
    // Test 3: N-Queens (4x4 board)
    cout << "\n3. 4-QUEENS SOLUTION:\n";
    vector<vector<int>> board(4, vector<int>(4, 0));
    
    if (solveNQueens(board, 0)) {
        cout << "Solution found:\n";
        printMatrix(board);
    } else {
        cout << "No solution exists\n";
    }
    
    // Test 4: Permutations
    cout << "\n4. PERMUTATIONS OF [1,2,3]:\n";
    vector<int> permNums = {1, 2, 3};
    vector<vector<int>> permutations;
    vector<int> currentPerm;
    vector<bool> used(permNums.size(), false);
    generatePermutations(permNums, currentPerm, used, permutations);
    
    for (const auto& perm : permutations) {
        printVector(perm);
        cout << "\n";
    }
    
    // Test 5: Simple Sudoku (partial board)
    cout << "\n5. SUDOKU SOLVER (Simple 4x4 example):\n";
    cout << "This demonstrates the same concept for larger problems!\n";
    
    return 0;
}

/*
=== THE BACKTRACKING TEMPLATE IN C++ ===

bool backtrack(parameters) {
    // BASE CASE
    if (reached_solution) {
        return true; // or add to results
    }
    
    // TRY ALL CHOICES
    for (each possible choice) {
        
        // MAKE CHOICE
        make_choice();
        
        // RECURSE
        if (backtrack(new_parameters)) {
            return true;
        }
        
        // BACKTRACK (UNDO CHOICE)
        undo_choice();
    }
    
    return false; // no solution found
}

KEY POINTS:
1. Always have a BASE CASE to stop recursion
2. Try all possible CHOICES at each step
3. MAKE the choice and recurse
4. UNDO the choice if it doesn't work (this is backtracking!)
5. Return false if no solution exists

COMMON PATTERNS:
- Use vectors for dynamic arrays
- Pass by reference (&) to avoid copying
- Use bool return type for "found/not found"
- Use void + result parameter for "find all solutions"
*/