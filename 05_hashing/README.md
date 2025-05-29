# Hashing - Quick Revision Notes

## Overview

Hashing is a technique to store and retrieve data efficiently using hash tables/arrays. It provides faster lookup times compared to linear search.

## 1. Number Hashing 

### Concept

- Use an array where index represents the number and value represents its frequency
- Direct indexing for fast O(1) access

### Code Implementation

```cpp
int hash[13] = {0};  // Initialize hash array
for(int i=0; i<n; i++){
    hash[arr[i]] += 1;  // Increment frequency
}
// Query: cout << hash[number] << endl;
```

### Memory Constraints

- **Inside main function:**
  - `int`: up to 10^6 elements
  - `bool`: up to 10^7 elements
- **Global arrays:**
  - `int`: up to 10^7 elements  
  - `bool`: up to 10^8 elements

### Limitations

- Only works for small range of numbers
- Wastes memory if range is large but sparse

## 2. Character Hashing

### For Lowercase Letters Only

```cpp
int hash[26] = {0};
hash[s[i] - 'a']++;  // Map 'a'->0, 'b'->1, etc.
// Query: cout << hash[c - 'a'] << endl;
```

### For All ASCII Characters

```cpp
int hash[256] = {0};  // Covers all ASCII
hash[s[i]]++;  // Direct ASCII value as index
// Query: cout << hash[c] << endl;
```

### Key Points

- Character to index mapping: `char - 'a'` for lowercase
- ASCII approach handles all characters including symbols

## 3. Map-based Hashing

### When to Use Maps

- Large number ranges (> 10^6)
- Sparse data (few unique elements)
- Unknown data range

### Map Implementation

```cpp
map<int, int> m;  // <element, frequency>
m[arr[i]]++;  // Auto-initialization to 0
// Query: cout << m[number] << endl;
```

### Map vs Unordered_map

| Feature | map | unordered_map |
|---------|-----|---------------|
| Time Complexity | O(log n) | O(1) avg, O(n) worst |
| Ordering | Sorted | No order |
| Memory | Less | More |

### For Strings

```cpp
map<char, int> charMap;  // Character frequency
```

## Quick Comparison

| Method | Best For | Time | Space | Range Limit |
|--------|----------|------|-------|-------------|
| Array Hash | Small range numbers | O(1) | O(max_val) | 10^6 - 10^7 |
| Char Hash | Characters | O(1) | O(26/256) | Fixed |
| Map | Large/unknown range | O(log n) | O(unique) | No limit |
| Unordered Map | Large range, speed priority | O(1) avg | O(unique) | No limit |

## Common Patterns

1. **Frequency Counting**: Count occurrences of elements
2. **Lookup**: Check if element exists and its count
3. **Precompute-Query**: Build hash table once, answer multiple queries

## Tips for Problem Solving

1. **Choose method based on constraints:**
   - Small range (≤10^6): Array hashing
   - Large range: Map/Unordered_map
   - Characters: Character hashing

2. **Memory considerations:**
   - Use global arrays for larger sizes
   - Consider bool arrays for presence-only checks

3. **Time vs Space tradeoff:**
   - Array hashing: More space, faster access
   - Map hashing: Less space, slightly slower

## Common Mistakes to Avoid

- Array out of bounds when using direct indexing
- Forgetting to initialize hash arrays
- Using wrong character mapping for different cases
- Not considering negative numbers in array hashing