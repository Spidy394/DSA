/*
    gcd(a, b) == gcd(a-b, b) , a>b

    ... 0
*/

// TC = O(Log5(min(a,b)))

# include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while(a>0 && b>0){
        if(a>b) a = a%b;
        else b = b%a;
    }

    if (a==0) return b;
    return a;
}

int main() {
    cout << gcd(18, 24);

    return 0;
}