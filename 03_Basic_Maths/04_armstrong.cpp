#include <bits/stdc++.h>
using namespace std;

int count_digit(int n){
    int cnt = 0;
    while(n != 0){
        cnt++;
        n /= 10;
    }
    return cnt;
}

bool armstrong(int n){
    int digit = count_digit(n);
    int sum = 0;
    int temp = n;
    while(temp != 0){
        sum += pow(temp % 10, digit);
        temp /= 10;
    }
    if (sum == n) return true;
    else return false;
}

int main() {
    cout << armstrong(371);
    return 0;
}


// TC = O(log₁₀(n))