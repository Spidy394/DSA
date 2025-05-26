# include <bits/stdc++.h>
using namespace std;

// int cnt = (int)(log10(n)+1);

int count_digit(int n){
    int count = 0;
    while(n != 0){
        count++;
        n = n/10;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    cout << "Number of digits: " << count_digit(n);

    return 0;
}

// TC - O(log₁₀(n))
// if division is involved then log comes