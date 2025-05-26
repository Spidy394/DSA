# Basic Mathematics in DSA

This document provides a quick revision of fundamental mathematical operations used in data structures and algorithms.

## Table of Contents

1. [Counting Digits](#counting-digits)
2. [Reversing Numbers](#reversing-numbers)
3. [Palindrome Numbers](#palindrome-numbers)
4. [Armstrong Numbers](#armstrong-numbers)
5. [Finding Divisors](#finding-divisors)
6. [Prime Numbers](#prime-numbers)
7. [GCD Calculation](#gcd-calculation)
8. [Euclidean Algorithm](#euclidean-algorithm)

## Counting Digits

Count the number of digits in an integer.

```cpp
int count_digit(int n) {
    int count = 0;
    while(n != 0) {
        count++;
        n = n/10;
    }
    return count;
}
```

Alternative method using logarithm:

```cpp
int count_digit(int n) {
    return (int)(log10(n) + 1);
}
```

**Time Complexity:** O(log₁₀(n))

## Reversing Numbers

Reverse the digits of a number.

```cpp
int reverse(int n) {
    int rev = 0;
    while(n != 0) {
        rev = rev*10 + (n%10);
        n /= 10;
    }
    return rev;
}
```

**Time Complexity:** O(log₁₀(n))

## Palindrome Numbers

Check if a number reads the same backward as forward.

```cpp
bool palindrome(int n) {
    if (n == reverse(n)) return true;
    else return false;
}
```

**Time Complexity:** O(log₁₀(n))

## Armstrong Numbers

An Armstrong number is a number that equals the sum of its digits each raised to the power of the total number of digits.

```cpp
bool armstrong(int n) {
    int digit = count_digit(n);
    int sum = 0;
    int temp = n;
    while(temp != 0) {
        sum += pow(temp % 10, digit);
        temp /= 10;
    }
    if (sum == n) return true;
    else return false;
}
```

**Time Complexity:** O(log₁₀(n))

## Finding Divisors

### Naive Approach

```cpp
void divisors(int n) {
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) cout << i << " ";
    }
}
```

**Time Complexity:** O(n)

### Optimized Approach

```cpp
void divisors(int n) {
    vector<int> ls;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            ls.push_back(i);
            if((n/i) != i) {
                ls.push_back(n/i);
            }
        }
    }
    sort(ls.begin(), ls.end());
    for(auto it: ls) cout << it << " ";
}
```

**Time Complexity:**

- Finding divisors: O(√n)
- Sorting: O(k log k) where k is the number of divisors
- Overall: O(√n + k log k)

## Prime Numbers

Check if a number is prime by counting its divisors.

```cpp
bool isPrime(int n) {
    int cnt = 0;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            cnt++;
            if((n/i) != i) cnt++;
        }
    }
    return (cnt == 2);
}
```

**Time Complexity:** O(√n)

## GCD Calculation

### Basic Approach

```cpp
int gcd(int x, int y) {
    int ans = 1;
    for(int i = 1; i <= min(x, y); i++) {
        if((x % i == 0) && (y % i == 0)) ans = i;
    }
    return ans;
}
```

**Time Complexity:** O(min(a, b))

## Euclidean Algorithm

An efficient algorithm to find GCD based on the principle: gcd(a, b) = gcd(a-b, b) if a > b.

```cpp
int gcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b) a = a % b;
        else b = b % a;
    }
    if(a == 0) return b;
    return a;
}
```

**Time Complexity:** O(log(min(a, b)))

## Key Mathematics Properties

1. **Division and Logarithmic Time**: When an algorithm uses division (like n/10), it typically has logarithmic time complexity.

2. **GCD Properties**:
   - gcd(a, b) = gcd(b, a mod b)
   - LCM(a, b) × GCD(a, b) = a × b

3. **Divisors**: The number of divisors of an integer is significantly less than the integer itself.

4. **Prime Checking**: We only need to check divisibility up to √n to determine if a number is prime.