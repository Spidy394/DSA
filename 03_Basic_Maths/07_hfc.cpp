# include <bits/stdc++.h>
using namespace std;

// TC = O(min(a, b))
void gcd(int x, int y){
    int ans = 1;
    for(int i=1; i<=min(x, y); i++){
        if ((x%i == 0) && (y%i == 0)) ans = i;
    }
    cout << ans;
}

int main() {
    gcd(18, 24);

    return 0;
}