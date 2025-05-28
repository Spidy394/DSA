# include <bits/stdc++.h>
using namespace std;

//parameterised method 
void sum1(int n, int sum){
    if(n<1){
        cout << sum;
        return;
    } 
    sum1(n-1, sum+n);
}

// functional method
int sum2(int n){
    if (n==0) return 0;
    return n + sum2(n-1);
}

int fact(int n){
    if(n == 0) return 1; 
    return n * fact(n-1);
}

int main() {
    sum1(10, 0);
    cout << endl;
    cout << sum2(11) << endl;
    cout << fact(5);

    return 0;
}