# include <bits/stdc++.h>
using namespace std;

int reverse(int n){
    int rev = 0;
    while(n!=0){
        rev = rev*10 + (n%10);
        n/=10;
    }

    return rev;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Reverse: " << reverse(n);

    return 0;
}

// TC = O(log₁₀(n))