# include <bits/stdc++.h>
using namespace std;

// TC = O(n)
void divisors(int n){
    for(int i = 1; i<=n; i++){
        if(n%i == 0) cout << i << " ";
    }
}

void divisors1(int n){
    vector<int> ls;
    // O(sqrt(n))
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            ls.push_back(i);
            if((n/i) != i){
                ls.push_back(n/i);
            }
        }
    }
    // O(n log n) -> no. of factors
    sort(ls.begin(), ls.end());
    // O(number of factors)
    for(auto it: ls) cout << it << " ";
}

int main() {
    // divisors(36);
    divisors1(36);

    return 0;
}
