# C++ STL Algorithms - Quick Revision Notes

This document provides a concise overview of C++ STL algorithms for quick revision.

## Non-modifying Algorithms

### Searching

- **find**, **find_if**, **find_if_not**: Find elements in a range
- **search**: Find a subsequence
- **binary_search**: Test if value exists in sorted range (returns bool)
- **lower_bound**: Find first element not less than value
- **upper_bound**: Find first element greater than value

```cpp
vector<int> v = {1, 2, 3, 4, 5};
auto it = find(v.begin(), v.end(), 3);           // Returns iterator to 3
auto it2 = find_if(v.begin(), v.end(), 
                  [](int x) { return x % 2 == 0; }); // First even number

// Binary search (on sorted containers)
bool exists = binary_search(v.begin(), v.end(), 3);  // true
auto lb = lower_bound(v.begin(), v.end(), 3);    // Iterator to 3
auto ub = upper_bound(v.begin(), v.end(), 3);    // Iterator to 4
```

### Counting & Comparing

- **count**, **count_if**: Count elements
- **equal**: Compare two ranges
- **mismatch**: Find first position where ranges differ
- **is_sorted**, **is_sorted_until**: Check if range is sorted

```cpp
int cnt = count(v.begin(), v.end(), 3);      // Number of 3's
int even = count_if(v.begin(), v.end(),  
                   [](int x) { return x % 2 == 0; }); // Count even numbers

vector<int> v2 = {1, 2, 3, 4, 5};
bool eq = equal(v.begin(), v.end(), v2.begin()); // true if identical
```

## Modifying Algorithms

### Transformations

- **copy**, **copy_if**, **copy_n**: Copy elements
- **transform**: Apply function to range
- **replace**, **replace_if**: Replace values
- **fill**, **fill_n**: Fill range with value
- **generate**, **generate_n**: Fill using function

```cpp
vector<int> source = {1, 2, 3, 4, 5};
vector<int> dest(source.size());
copy(source.begin(), source.end(), dest.begin());

// Transform each element
transform(v.begin(), v.end(), v.begin(), 
          [](int x) { return x * 2; });  // Doubles each value

// Replace values
replace(v.begin(), v.end(), 3, 30);      // Replace 3 with 30

// Fill with value
fill(v.begin(), v.end(), 0);              // Fill with zeros
```

### Removal & Erasure

- **remove**, **remove_if**: Remove elements (returns new end)
- **unique**: Remove consecutive duplicates
- **erase**: Erase using iterator (container member function)
- **erase-remove idiom**: Combination of erase and remove

```cpp
// Remove doesn't change container size, just reorders
auto new_end = remove(v.begin(), v.end(), 3);  
v.erase(new_end, v.end());                    // Actually remove

// Erase-remove idiom
v.erase(remove(v.begin(), v.end(), 3), v.end());

// Remove with condition
v.erase(remove_if(v.begin(), v.end(), 
                 [](int x) { return x % 2 == 0; }), v.end()); // Remove even
```

## Sorting & Ordering Algorithms

### Sorting

- **sort**: Sort elements in range
- **stable_sort**: Sort preserving relative order of equal elements
- **partial_sort**: Sort part of range
- **nth_element**: Partition at nth position

```cpp
vector<int> v = {5, 2, 4, 1, 3};
sort(v.begin(), v.end());                   // Ascending: {1, 2, 3, 4, 5}
sort(v.begin(), v.end(), greater<int>());   // Descending: {5, 4, 3, 2, 1}

// Custom comparator
sort(v.begin(), v.end(), 
    [](int a, int b) { return a > b; });    // Descending

// Partial sort (first 3 elements)
partial_sort(v.begin(), v.begin()+3, v.end()); // First 3 sorted
```

### Partitioning & Permuting

- **partition**, **stable_partition**: Divide elements by condition
- **reverse**: Reverse range
- **rotate**: Rotate elements
- **shuffle**: Randomly reorder elements
- **next_permutation**, **prev_permutation**: Generate permutations

```cpp
// Partition: move all even numbers to front
auto it = partition(v.begin(), v.end(), 
                   [](int x) { return x % 2 == 0; });

// Reverse
reverse(v.begin(), v.end());

// Rotate (shifts elements)
rotate(v.begin(), v.begin() + 2, v.end());  // Rotates left by 2

// Shuffle (C++11 and later)
random_device rd;
mt19937 g(rd());
shuffle(v.begin(), v.end(), g);
```

## Numeric Algorithms

- **accumulate**: Sum elements
- **reduce**: Similar to accumulate (parallel)
- **inner_product**: Compute inner product
- **partial_sum**: Compute partial sums
- **adjacent_difference**: Compute differences between adjacent elements

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// Sum of elements
int sum = accumulate(v.begin(), v.end(), 0);     // 15

// Product of elements
int product = accumulate(v.begin(), v.end(), 1,
                        multiplies<int>());      // 120

// Using custom operation
int sum_squares = accumulate(v.begin(), v.end(), 0,
                           [](int sum, int x) { return sum + x*x; }); // 55
```

## Min/Max Operations

- **min**, **max**: Find minimum/maximum of two values
- **minmax**: Find both minimum and maximum of two values
- **min_element**, **max_element**, **minmax_element**: Find min/max in range

```cpp
int minimum = min(5, 10);                        // 5
int maximum = max(5, 10);                        // 10

// Find min/max in container
auto min_it = min_element(v.begin(), v.end());   // Iterator to smallest
auto max_it = max_element(v.begin(), v.end());   // Iterator to largest

// Get both in one call
auto [min_it, max_it] = minmax_element(v.begin(), v.end()); // C++17
```

## Heap Operations

- **make_heap**: Create heap from range
- **push_heap**: Add element to heap
- **pop_heap**: Remove largest element
- **sort_heap**: Sort heap
- **is_heap**, **is_heap_until**: Check if range is a heap

```cpp
vector<int> v = {3, 1, 4, 1, 5};
make_heap(v.begin(), v.end());                   // Reorganizes into heap

v.push_back(9);
push_heap(v.begin(), v.end());                   // Add to heap

pop_heap(v.begin(), v.end());                    // Move largest to end
int largest = v.back();
v.pop_back();                                    // Remove largest

sort_heap(v.begin(), v.end());                   // Sort heap
```

## Performance Considerations

- Most STL algorithms are optimized for performance
- Time complexity is generally optimal for the task
- Many algorithms have overloads for custom comparators/predicates
- Consider using parallel execution policies (C++17) for large datasets

```cpp
// Parallel execution (C++17)
#include <execution>
sort(execution::par, v.begin(), v.end());        // Parallel sort
```

## Common Algorithm Categories

| Category | Examples | Use Cases |
|----------|----------|-----------|
| Non-modifying | find, count, binary_search | When you need to examine elements without changing them |
| Modifying | copy, transform, replace | When you need to change elements or create modified copies |
| Sorting | sort, partial_sort, nth_element | When order matters |
| Partitioning | partition, stable_partition | When you need to group elements by a condition |
| Numeric | accumulate, partial_sum | For mathematical operations |
| Heap | make_heap, push_heap | For priority queue operations |