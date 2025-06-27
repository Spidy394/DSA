# Sorting Algorithms - Quick Revision Notes

## Overview

Sorting algorithms arrange elements in a specific order (ascending/descending). These are fundamental algorithms with different time and space complexities.

## 1. Selection Sort

### How It Works

- Find the minimum element and swap it with the first element
- Find the second minimum and swap with second position
- Continue until array is sorted

### Code Implementation

```cpp
void selection_sort(int arr[], int n){
    for(int i=0; i<=n-2; i++){
        int min = i;
        for(int j=i; j<=n-1; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}
```

### Time & Space Complexity

- **Time**: O(n²) for all cases (best, average, worst)
- **Space**: O(1) - in-place sorting
- **Stability**: Not stable (relative order may change)

### Key Features

- Always performs n-1 swaps
- Good when memory writes are costly
- Simple implementation

## 2. Bubble Sort

### How It Works

- Compare adjacent elements and swap if in wrong order
- After each pass, largest element "bubbles up" to correct position
- Continue until no swaps needed

### Code Implementation

```cpp
void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=1; i--){
        int isSwap = 0; // optimization for best case
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwap++;
            }
        }
        if(!isSwap) break; // early termination
    }
}
```

### Time & Space Complexity

- **Time**:
  - Best: O(n) with optimization
  - Average/Worst: O(n²)
- **Space**: O(1) - in-place sorting
- **Stability**: Stable (maintains relative order)

### Optimization Features

- Early termination when no swaps occur in a pass
- Reduces best case to O(n) for already sorted arrays

## 3. Insertion Sort

### How It Works

- Build sorted array one element at a time
- Take element and insert it in correct position in sorted portion
- Shift elements as needed

### Code Implementation

```cpp
void insertion_sort(int arr[], int n){
    for(int i=0; i<=n-1; i++){
        int j = i;
        while(j>0 && (arr[j-1] > arr[j])){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}
```

### Time & Space Complexity

- **Time**:
  - Best: O(n) for nearly sorted arrays
  - Average/Worst: O(n²)
- **Space**: O(1) - in-place sorting
- **Stability**: Stable

### Key Features

- Efficient for small datasets
- Works well for nearly sorted arrays
- Online algorithm (can sort as data arrives)

## Quick Comparison

| Algorithm | Best Case | Average Case | Worst Case | Space | Stable | Use Case |
|-----------|-----------|--------------|------------|-------|--------|----------|
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No | Memory writes are costly |
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Educational purposes |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Small/nearly sorted data |

## Key Concepts

### Stability

- **Stable**: Equal elements maintain their relative order
- **Unstable**: Equal elements may change relative positions

### In-place Sorting

- Uses only O(1) extra space
- Modifies input array directly

### Adaptive Algorithms

- Performance improves for partially sorted input
- Insertion sort and optimized bubble sort are adaptive

## When to Use Each Algorithm

### Selection Sort Usage

- When memory writes are expensive
- When you need exactly n-1 swaps
- Simple implementation needed

### Bubble Sort Usage

- Educational purposes (easy to understand)
- When stability is required and data is small
- Rarely used in practice

### Insertion Sort Usage

- Small datasets (< 50 elements)
- Nearly sorted data
- As subroutine in hybrid algorithms (like Timsort)
- Online sorting requirements

## Common Optimizations

1. **Early Termination**: Stop when no swaps/shifts occur
2. **Binary Insertion**: Use binary search in insertion sort
3. **Hybrid Approaches**: Switch algorithms based on data size

## Practice Tips

1. **Understand the invariants**: What remains true after each iteration
2. **Trace through examples**: Follow algorithm step-by-step on small arrays
3. **Identify patterns**: How many passes, comparisons, swaps needed
4. **Consider edge cases**: Empty arrays, single elements, sorted/reverse sorted

## Implementation Notes

- All three algorithms modify arrays in-place
- Use 0-based indexing in implementations
- Loop bounds are crucial for correctness
- Swap operations can be optimized based on requirements