# C++ STL Containers - Quick Revision Notes

This document provides a concise overview of C++ STL containers for quick revision.

## 1. Sequence Containers

### Vector

- **Dynamic array** with automatic resizing
- **Continuous memory** storage
- **Random access** - O(1)
- **Insertion/deletion at end** - Amortized O(1)
- **Insertion/deletion at middle/beginning** - O(n)

```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);        // Add element at end
v.pop_back();          // Remove last element
v[0] = 10;             // Direct access
v.size();              // Number of elements
v.capacity();          // Allocated space
v.reserve(100);        // Pre-allocate memory
v.resize(10);          // Change size
```

### List

- **Doubly-linked list**
- **Non-contiguous** memory
- **No random access** - O(n) access
- **Fast insertion/deletion anywhere** - O(1)
- **No reallocation** when adding elements

```cpp
list<int> l = {1, 2, 3};
l.push_back(4);        // Add at end
l.push_front(0);       // Add at beginning
l.pop_back();          // Remove from end
l.pop_front();         // Remove from beginning
l.sort();              // Sort elements
l.reverse();           // Reverse order
```

### Deque (Double-ended queue)

- **Double-ended queue**
- **Fast insertion/deletion at both ends** - O(1)
- **Random access** - O(1)
- **Not guaranteed contiguous** memory

```cpp
deque<int> d = {1, 2, 3};
d.push_back(4);        // Add at end
d.push_front(0);       // Add at beginning
d[0] = 10;             // Direct access
```

## 2. Container Adaptors

### Stack

- **LIFO** (Last In, First Out) data structure
- Built on top of another container (default: deque)

```cpp
stack<int> s;
s.push(10);            // Add element
s.pop();               // Remove top element
s.top();               // Access top element
s.size();              // Number of elements
s.empty();             // Check if empty
```

### Queue

- **FIFO** (First In, First Out) data structure
- Built on top of another container (default: deque)

```cpp
queue<int> q;
q.push(10);            // Add element
q.pop();               // Remove front element
q.front();             // Access front element
q.back();              // Access back element
q.size();              // Number of elements
```

### Priority Queue

- **Heap** data structure
- Always provides **largest element** at top (by default)
- O(log n) insertion and deletion

```cpp
priority_queue<int> pq;
pq.push(30);           // Add element
pq.push(10);
pq.push(20);
pq.top();              // Returns 30 (highest)
pq.pop();              // Removes highest element

// Min heap
priority_queue<int, vector<int>, greater<int>> min_pq;
```

## 3. Associative Containers

### Set

- **Sorted unique** elements
- Based on **balanced binary tree** (typically Red-Black)
- O(log n) insertion, deletion, and search
- No modification of elements (read-only)

```cpp
set<int> s = {3, 1, 2, 1};   // Stores {1, 2, 3}
s.insert(4);                  // Insert element
s.erase(2);                   // Remove element
s.count(1);                   // Returns 1 (exists)
s.find(3);                    // Iterator to element
```

### Multiset

- Like set, but **allows duplicates**

```cpp
multiset<int> ms = {3, 1, 2, 1};  // Stores {1, 1, 2, 3}
ms.count(1);                       // Returns 2
```

### Map

- **Key-value** pairs
- **Sorted by key** (unique keys)
- O(log n) insertion, deletion, and search

```cpp
map<string, int> m;
m["apple"] = 5;               // Insert or update
m.insert({"banana", 3});      // Another way to insert
m.at("apple");                // Access with bounds check
m["apple"];                   // Access or create
m.erase("banana");            // Remove by key
```

### Multimap

- Like map, but **allows duplicate keys**

```cpp
multimap<string, int> mm;
mm.insert({"apple", 5});
mm.insert({"apple", 10});     // Both entries exist
```

## 4. Unordered Containers

### Unordered Set/Map

- **Hash table** implementation
- **Average O(1)** operations
- **No ordering** guaranteed
- **Unordered_set** - unique elements
- **Unordered_map** - key-value pairs (unique keys)

```cpp
unordered_set<int> us = {4, 1, 3, 2};
unordered_map<string, int> um;
um["apple"] = 5;
```

## Common Iterator Operations

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// Different ways to iterate
for(auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}

for(auto& elem : v) {
    cout << elem << " ";
}

// Iterator functions
auto it = v.begin();          // First element
auto it_end = v.end();        // Past-the-end
auto it_rev = v.rbegin();     // First element (reversed)
```

## Performance Comparison

| Container        | Access    | Insert/Delete (begin) | Insert/Delete (end) | Insert/Delete (middle) | Search    |
|------------------|-----------|----------------------|---------------------|------------------------|-----------|
| vector           | O(1)      | O(n)                 | O(1)*               | O(n)                  | O(n)      |
| list             | O(n)      | O(1)                 | O(1)                | O(1)**                | O(n)      |
| deque            | O(1)      | O(1)                 | O(1)                | O(n)                  | O(n)      |
| set/map          | O(log n)  | O(log n)             | O(log n)            | O(log n)              | O(log n)  |
| unordered_set/map| O(1)***   | O(1)***              | O(1)***             | O(1)***               | O(1)***   |

\* Amortized constant time  
\** With iterator position  
\*** Average case, O(n) worst case