# 🚀 DSA Quick Reference Cheat Sheet

## 📊 **Time Complexity Comparison**

| Algorithm | Best Case | Average Case | Worst Case | Space |
|-----------|-----------|--------------|------------|-------|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) |
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) |
| **Heap Sort** | O(n log n) | O(n log n) | O(n log n) | O(1) |

## 🔍 **Search Algorithms**

| Algorithm | Time Complexity | Space Complexity | When to Use |
|-----------|----------------|------------------|-------------|
| **Linear Search** | O(n) | O(1) | Unsorted arrays, small datasets |
| **Binary Search** | O(log n) | O(1) | Sorted arrays |
| **Depth First Search** | O(V + E) | O(V) | Graph traversal, backtracking |
| **Breadth First Search** | O(V + E) | O(V) | Shortest path, level-wise traversal |

## 📚 **Data Structure Operations**

### **Arrays**
- Access: O(1)
- Search: O(n)
- Insert: O(n) (at end: O(1))
- Delete: O(n) (at end: O(1))

### **Linked Lists**
- Access: O(n)
- Search: O(n)
- Insert: O(1) (at beginning)
- Delete: O(1) (at beginning)

### **Stacks & Queues**
- Push/Pop/Enqueue/Dequeue: O(1)
- Search: O(n)
- Access: O(n)

### **Trees**
- Search: O(log n) (balanced BST)
- Insert: O(log n) (balanced BST)
- Delete: O(log n) (balanced BST)

## 🎯 **Common Problem Patterns**

### **Two Pointers**
- **Use Case:** Array problems, palindrome, two sum
- **Example:** `1-Array/question/10-swapthealternate.cpp`

### **Sliding Window**
- **Use Case:** Subarray problems, string problems
- **Example:** `1-Array/Sliding Window/slidingwindow.cpp`

### **Kadane's Algorithm**
- **Use Case:** Maximum subarray sum
- **Example:** `1-Array/Kadan Algorithm/kadanalgorithm.cpp`

### **Monotonic Stack/Queue**
- **Use Case:** Next greater element, stock span
- **Example:** `Monotonoic Stack and Monotonoic Queue/`

## 🔧 **Implementation Tips**

### **Recursion Base Cases**
```cpp
// Always define base cases first
if (n <= 1) return n;
if (n == 0) return 1;
```

### **Two Pointer Technique**
```cpp
int left = 0, right = n - 1;
while (left < right) {
    // Process elements
    left++;
    right--;
}
```

### **Sliding Window**
```cpp
int left = 0, right = 0;
while (right < n) {
    // Expand window
    right++;
    
    // Shrink window if needed
    while (condition) {
        left++;
    }
}
```

## 📝 **Common Mistakes to Avoid**

1. **Forgetting Edge Cases**
   - Empty arrays/strings
   - Single element
   - All same elements

2. **Not Considering Space Complexity**
   - Recursive solutions can cause stack overflow
   - Extra space for temporary arrays

3. **Inefficient String Operations**
   - String concatenation in loops
   - Not using StringBuilder/StringBuffer

4. **Array Bounds**
   - Always check array bounds
   - Handle negative indices

## 🎓 **Interview Preparation Tips**

1. **Before Coding:**
   - Clarify input/output
   - Ask about edge cases
   - Discuss approach with interviewer

2. **While Coding:**
   - Write clean, readable code
   - Use meaningful variable names
   - Add comments for complex logic

3. **After Coding:**
   - Test with examples
   - Discuss time/space complexity
   - Mention optimizations

## 🔗 **Quick Links to Your Files**

- **Arrays:** `1-Array/`
- **Linked Lists:** `2-Linked-List/`
- **Trees:** `Tree/`
- **DP:** `Dynamic Programming/`
- **Graphs:** `Graph/`
- **Recursion:** `Recursion/`

---
*Keep this handy during practice sessions!*
