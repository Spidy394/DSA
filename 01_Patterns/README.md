# Patterns Implemented

1. **Pattern 1**: Square of stars
    ```
    *****
    *****
    *****
    *****
    *****
    ```
2. **Pattern 2**: Right-angled triangle of stars
    ```
    *
    **
    ***
    ****
    *****
    ```
3. **Pattern 3**: Right-angled triangle of numbers
    ```
    1
    12
    123
    1234
    12345
    ```
4. **Pattern 4**: Right-angled triangle of repeated numbers
    ```
    1
    22
    333
    4444
    55555
    ```
5. **Pattern 5**: Inverted right-angled triangle of stars
    ```
    *****
    ****
    ***
    **
    *
    ```
6. **Pattern 6**: Inverted right-angled triangle of numbers
    ```
    12345
    1234
    123
    12
    1
    ```
7. **Pattern 7**: Pyramid of stars
    ```
        *
       ***
      *****
     *******
    *********
    ```
8. **Pattern 8**: Inverted pyramid of stars
    ```
    *********
     *******
      *****
       ***
        *
    ```
9. **Pattern 9**: Combined pyramid and inverted pyramid of stars
    ```
        *
       ***
      *****
     *******
    *********
    *********
     *******
      *****
       ***
        *
    ```
10. **Pattern 10**: Diamond of stars
    ```
    *
    **
    ***
    ****
    *****
    ****
    ***
    **
    *
    ```
11. **Pattern 11**: Binary triangle
    ```
    1
    01
    101
    0101
    10101
    ```
12. **Pattern 12**: Number pyramid with spaces
    ```
    1        1
    12      21
    123    321
    1234  4321
    1234554321
    ```
13. **Pattern 13**: Floyd's triangle
    ```
    1
    2 3
    4 5 6
    7 8 9 10
    11 12 13 14 15
    ```
14. **Pattern 14**: Alphabet triangle
    ```
    A
    A B
    A B C
    A B C D
    A B C D E
    ```
15. **Pattern 15**: Inverted alphabet triangle
    ```
    A B C D E
    A B C D
    A B C
    A B
    A
    ```
16. **Pattern 16**: Repeated alphabet triangle
    ```
    A
    B B
    C C C
    D D D D
    E E E E E
    ```
17. **Pattern 17**: Pyramid of characters
    ```
        A
       ABA
      ABCBA
     ABCDCBA
    ABCDEDCBA
    ```
18. **Pattern 18**: Inverted alphabet pyramid
    ```
    E
    D E
    C D E
    B C D E
    A B C D E
    ```
19. **Pattern 19**: Hourglass pattern of stars
    ```
    **********
    ****  ****
    ***    ***
    **      **
    *        *
    *        *
    **      **
    ***    ***
    ****  ****
    **********
    ```
20. **Pattern 20**: Diamond pattern with spaces
    ```
    *        *
    **      **
    ***    ***
    ****  ****
    **********
    **********
    ****  ****
    ***    ***
    **      **
    *        *
    ```
21. **Pattern 21**: Hollow square of stars
    ```
    *****
    *   *
    *   *
    *   *
    *****
    ```
22. **Pattern 22**: Concentric squares of numbers
    ```
    555555555
    544444445
    543333345
    543222345
    543212345
    543222345
    543333345
    544444445
    555555555
    ```

## How to Run

1. Make sure you have a C++ compiler installed.
2. Compile the `main.cpp` file:
    ```sh
    g++ main.cpp -o patterns
    ```
3. Run the executable:
    ```sh
    ./patterns
    ```

## Example

The current implementation in `main.cpp` runs `pattern22` with `n = 5`. You can modify the `main` function to call any other pattern function with your desired value of `n`.

```cpp
int main(){
    int t = 1, n = 5;

    for (int i = 0; i < t; i++){
        pattern22(n);
    }

    return 0;
}
```