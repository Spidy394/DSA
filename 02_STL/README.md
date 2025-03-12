# C++ Standard Template Library (STL)

This directory contains examples of C++ STL data structures and algorithms. The STL is a powerful library that provides ready-to-use data structures and functions that simplify C++ programming.

## Contents

1. [Pairs](#pairs)
2. [Vectors](#vectors)
3. [Lists](#lists)

## Pairs

A `pair` is a simple container to store two values which may be of different types.

### Key Features

- Store two heterogeneous objects as a single unit
- Access elements using `.first` and `.second`
- Can be nested (pairs within pairs)

### Examples

```cpp
// Basic pair usage
pair<int, int> p1 = {1, 3};
cout << p1.first << " " << p1.second << endl; // Output: 1 3

// Nested pair
pair<int, pair<int, int>> p2 = {1, {3, 5}};
cout << p2.first << " " << p2.second.first << " " << p2.second.second; // Output: 1 3 5

// Array of pairs
pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}};
```

## Vectors

A `vector` is a dynamic array that can grow or shrink in size.

### Key Features

- Dynamic size
- Contiguous memory allocation
- Random access using indices
- Efficient insertion/deletion at the end

### Common Operations

```cpp
// Initialization
vector<int> v;                // Empty vector
vector<int> v1(5, 10);        // Vector of size 5 with all elements as 10
vector<int> v2(v1);           // Copy of v1

// Insertion
v.push_back(1);               // Add element at the end
v.emplace_back(2);            // More efficient than push_back
v.insert(v.begin() + 1, 5);   // Insert 5 at index 1
v.insert(v.begin() + 1, 3, 10); // Insert 3 copies of 10 at index 1

// Access
cout << v[0];                 // Access by index
cout << v.at(1);              // Safer access with bounds checking
cout << v.front();            // First element
cout << v.back();             // Last element

// Deletion
v.pop_back();                 // Remove last element
v.erase(v.begin() + 1);       // Remove element at index 1
v.erase(v.begin() + 1, v.begin() + 3); // Remove range of elements
v.clear();                    // Remove all elements

// Size operations
cout << v.size();             // Get number of elements
cout << v.empty();            // Check if vector is empty
```

### Iteration

```cpp
// Using iterators
for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}

// Using auto keyword (C++11)
for(auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}

// Range-based for loop (C++11)
for(auto element : v) {
    cout << element << " ";
}
```

## Lists

A `list` is implemented as a doubly linked list, allowing constant time insertion and removal anywhere in the sequence.

### Key Features

- Non-contiguous memory allocation
- No random access
- Efficient insertion/deletion at any position
- Bidirectional iteration

### Common Operations

```cpp
// Basic operations
list<int> l;
l.push_back(10);       // Add to end
l.push_front(5);       // Add to beginning
l.pop_back();          // Remove from end
l.pop_front();         // Remove from beginning

// Additional operations
l.sort();              // Sort the list
l.reverse();           // Reverse the list
l.merge(list2);        // Merge with another list
```
