# Sorting Algorithms - Complete Quick Revision Notes

## Overview

Sorting algorithms arrange elements in a specific order (ascending/descending). This guide covers both basic O(n²) algorithms and advanced O(n log n) algorithms with their implementations and analysis.

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

## 4. Merge Sort

### How It Works

- Divide array into two halves recursively
- Sort both halves independently
- Merge the sorted halves to get final sorted array

### Code Implementation

```cpp
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low, right = mid+1;
    
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }
    
    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);
    
    for(int i=low; i<=high; i++){
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
```

### Time & Space Complexity

- **Time**: O(n log n) for all cases (best, average, worst)
- **Space**: O(n) - requires extra space for merging
- **Stability**: Stable (maintains relative order)

### Key Features

- Guaranteed O(n log n) performance
- Stable sorting algorithm
- Good for large datasets
- Predictable performance

## 5. Quick Sort

### How It Works

- Choose a pivot element
- Partition array: elements ≤ pivot on left, > pivot on right
- Recursively sort left and right partitions

### Code Implementation

```cpp
int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    
    while(i < j){
        while(arr[i] <= pivot && i <= high) i++;
        while(arr[j] > pivot && j >= low) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
```

### Time & Space Complexity

- **Time**:
  - Best/Average: O(n log n)
  - Worst: O(n²) - when pivot is always smallest/largest
- **Space**: O(log n) - recursion stack space
- **Stability**: Not stable

### Key Features

- In-place sorting (except recursion stack)
- Average case faster than merge sort
- Cache-friendly due to in-place nature
- Widely used in practice

## 6. Recursive Variations

### Recursive Bubble Sort

```cpp
void recBubbleSort(vector<int> &arr, int n){
    if(n == 1) return;
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
    }
    recBubbleSort(arr, n-1);
}
```

### Recursive Insertion Sort

```cpp
void recInsertionSort(vector<int> &arr, int n){
    if(n <= 1) return;
    recInsertionSort(arr, n-1);
    
    int last = arr[n-1];
    int j = n-2;
    while(j >= 0 && arr[j] > last){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}
```

## Complete Algorithm Comparison

| Algorithm | Best Case | Average Case | Worst Case | Space | Stable | In-Place | Use Case |
|-----------|-----------|--------------|------------|-------|--------|----------|----------|
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No | Yes | Memory writes costly |
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes | Educational/Small data |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes | Small/Nearly sorted |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | No | Large datasets |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No | Yes | General purpose |

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

### Basic Sorting Algorithms (O(n²))

#### Selection Sort Usage

- When memory writes are expensive
- When you need exactly n-1 swaps
- Simple implementation needed

#### Bubble Sort Usage

- Educational purposes (easy to understand)
- When stability is required and data is small
- Detecting if array is already sorted

#### Insertion Sort Usage

- Small datasets (< 50 elements)
- Nearly sorted data
- As subroutine in hybrid algorithms (like Timsort)
- Online sorting requirements

### Advanced Sorting Algorithms (O(n log n))

#### Merge Sort Usage

- When stable sorting is required
- Large datasets with guaranteed O(n log n) performance
- External sorting (sorting data that doesn't fit in memory)
- When worst-case performance matters

#### Quick Sort Usage

- General purpose sorting (most commonly used)
- When average-case performance is priority
- In-place sorting requirements
- Cache-friendly sorting needed

## Algorithm Selection Guide

```text
Data Size < 50:           Insertion Sort
Nearly Sorted:            Insertion Sort
Stability Required:       Merge Sort or Bubble Sort
Memory Constrained:       Quick Sort or Heap Sort
Guaranteed Performance:   Merge Sort
General Purpose:          Quick Sort
Educational:              Bubble Sort
```

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

## Memory Tricks for Quick Revision

### Basic Algorithms

#### Selection Sort - "Select the minimum"

- **Pattern**: Find min → Swap → Move forward
- **Mnemonic**: "SELECT the smallest, SORT by position"
- **Key Loop**: Outer loop stops at n-2 (last element auto-sorted)

#### Bubble Sort - "Bubble up the largest"

- **Pattern**: Compare adjacent → Swap if wrong → Largest bubbles to end
- **Mnemonic**: "BUBBLE the biggest to the back"
- **Key Loop**: Outer loop decrements from n-1 to 1

#### Insertion Sort - "Insert in sorted portion"

- **Pattern**: Take element → Find position → Shift and insert
- **Mnemonic**: "INSERT like sorting playing cards"
- **Key Loop**: Inner while loop shifts elements backward

### Advanced Algorithms

#### Merge Sort - "Divide and Conquer"

- **Pattern**: Divide → Sort → Merge
- **Mnemonic**: "MERGE two sorted halves"
- **Key**: Always O(n log n), uses extra space

#### Quick Sort - "Pivot and Partition"

- **Pattern**: Choose pivot → Partition → Recurse
- **Mnemonic**: "QUICK with good pivot choice"
- **Key**: In-place, but O(n²) in worst case

## Common Interview Questions

1. **Which is most efficient for small arrays?** Insertion Sort
2. **Which requires exactly n-1 swaps?** Selection Sort
3. **Which can detect if array is already sorted?** Bubble Sort (optimized)
4. **Which guarantees O(n log n) performance?** Merge Sort
5. **Which is fastest on average for large datasets?** Quick Sort
6. **Which algorithms are stable?** Bubble Sort, Insertion Sort, Merge Sort
7. **Which uses least extra memory?** Selection Sort, Bubble Sort, Insertion Sort
8. **Best for nearly sorted data?** Insertion Sort
9. **Best for external sorting?** Merge Sort
10. **Most commonly used in practice?** Quick Sort variations

## Quick Debug Checklist

- ✅ Array bounds (0 to n-1)
- ✅ Loop termination conditions
- ✅ Swap function correctness
- ✅ Handle single element/empty arrays
- ✅ Verify stability requirements

## Time Complexity Cheat Sheet

```text
Basic Algorithms (O(n²)):
Selection Sort:  Always O(n²)
Bubble Sort:     Best O(n), Avg/Worst O(n²) 
Insertion Sort:  Best O(n), Avg/Worst O(n²)

Advanced Algorithms (O(n log n)):
Merge Sort:      Always O(n log n)
Quick Sort:      Best/Avg O(n log n), Worst O(n²)
```

## Key Implementation Points

### Recursive vs Iterative

- **Basic algorithms**: Both versions exist, iterative more common
- **Advanced algorithms**: Naturally recursive (divide-and-conquer)
- **Tail recursion**: Can be optimized to iterative

### Important Edge Cases

- Empty array (n = 0)
- Single element (n = 1)
- Already sorted array
- Reverse sorted array
- All elements same
- Array with duplicates

**Remember**:

- Only optimized Bubble Sort and Insertion Sort achieve O(n) best case
- Merge Sort guarantees O(n log n) but uses O(n) space
- Quick Sort is fastest on average but has O(n²) worst case