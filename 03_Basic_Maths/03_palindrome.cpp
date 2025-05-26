# include <bits/stdc++.h>
using namespace std;

int reverse(int n){
    int rev=0;
    while(n>0){
        rev = rev*10 + n%10;
        n/=10;
    }
    return rev;
}

bool palindrome(int n){
    if (n == reverse(n)) return true;
    else return false;
}

int main() {
    cout << palindrome(121);

    return 0;
}

// tc = O(log₁₀(n))