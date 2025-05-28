# Recursion - Quick Revision Notes

Recursion is a programming technique where a function calls itself to solve a problem by breaking it down into simpler subproblems.

## Table of Contents

1. [Basic Concepts](#basic-concepts)
2. [Simple Recursion Examples](#simple-recursion-examples)
3. [Recursive Patterns](#recursive-patterns)
4. [Array Operations with Recursion](#array-operations-with-recursion)
5. [String Operations with Recursion](#string-operations-with-recursion)
6. [Multiple Recursive Calls](#multiple-recursive-calls)

## Basic Concepts

### Key Components of Recursion

- **Base Case**: Condition to stop recursion
- **Recursive Case**: Function calling itself with modified parameters
- **Stack Space**: Each call is stored in the call stack

### Complexity Analysis

- **Time Complexity**: Number of function calls × time per call
- **Space Complexity**: Maximum depth of recursion stack

## Simple Recursion Examples

### Print a Name N Times

```cpp
void printName(int i, int n) {
    if(i > n) return;       // Base case
    cout << "Spydi" << endl;
    printName(i+1, n);      // Recursive call
}
```

- **TC**: O(n) - n recursive calls
- **SC**: O(n) - maximum call stack depth is n

### Print Numbers from 1 to N

```cpp
// Forward printing (1 to N)
void printl(int i, int n) {
    if(i > n) return;       // Base case
    cout << i << " ";
    printl(i+1, n);         // Recursive call
}

// Using backtracking (1 to N)
void print(int n) {
    if(n < 1) return;       // Base case
    print(n-1);             // Recursive call
    cout << n << " ";
}
```

### Print Numbers from N to 1

```cpp
// Reverse printing (N to 1)
void printr(int n) {
    if(n < 1) return;       // Base case
    cout << n << " ";
    printr(n-1);            // Recursive call
}

// Using backtracking (N to 1)
void print2(int i, int n) {
    if(i > n) return;       // Base case
    print2(i+1, n);         // Recursive call
    cout << i << " ";
}
```

## Recursive Patterns

### Parameterized Recursion

Pass result as parameter and build during recursive calls.

```cpp
// Sum of first n numbers
void sum1(int n, int sum) {
    if(n < 1) {
        cout << sum;
        return;
    } 
    sum1(n-1, sum+n);    // Pass accumulated sum
}
```

### Functional Recursion

Return values from functions and combine results.

```cpp
// Sum of first n numbers
int sum2(int n) {
    if (n == 0) return 0;   // Base case
    return n + sum2(n-1);   // Return and combine
}

// Factorial of n
int fact(int n) {
    if(n == 0) return 1;    // Base case
    return n * fact(n-1);   // Return and combine
}
```

## Array Operations with Recursion

### Reverse an Array

```cpp
// Two-pointer approach
void rev(int l, int r, int arr[]) {
    if(l >= r) return;                // Base case
    swap(arr[l], arr[r]);
    rev(l+1, r-1, arr);               // Recursive call with narrowed window
}

// Single-pointer approach
void reverse(int i, int n, int arr[]) {
    if(i >= n/2) return;              // Base case
    swap(arr[i], arr[n-i-1]);
    reverse(i+1, n, arr);             // Recursive call with incremented index
}
```

## String Operations with Recursion

### Check Palindrome

```cpp
bool f(int i, string s) {
    if(i >= s.size()/2) return true;        // Base case
    if(s[i] != s[s.size()-i-1]) return false; // Check current pair
    return f(i+1, s);                        // Check next pair
}
```

## Multiple Recursive Calls

### Fibonacci Sequence

```cpp
int f(int n) {
    if (n <= 1) return n;         // Base case
    int last = f(n-1);            // First recursive call
    int slast = f(n-2);           // Second recursive call
    return last + slast;
}
```

- **TC**: O(2ⁿ) - exponential due to repeated calculations
- **SC**: O(n) - maximum call stack depth is n

## Key Recursion Strategies

1. **Forward Recursion**: Process on the way down the recursion tree
2. **Backward Recursion (Backtracking)**: Process on the way up the recursion tree
3. **Tree Recursion**: Multiple recursive calls in one function (like Fibonacci)

## Tips for Better Recursion

1. Always identify and handle the base case correctly
2. Ensure parameters change in a way that reaches the base case
3. When stuck, try visualizing the recursion tree
4. Watch for overlapping subproblems (can be optimized with memoization)
5. Mind the stack space - very deep recursion can cause stack overflow
