# include <bits/stdc++.h>
using namespace std;

void printl(int i, int n){
    if(i>n) return;
    cout << i << " ";
    printl(i+1, n);
}

// backtracking 
void print(int n){
    if(n<1) return;
    print(n-1);
    cout << n << " ";
}


void printr(int n){
    if(n<1) return;
    cout << n << " ";
    printr(n-1);
}

// bracktracking
void print2(int i, int n){
   if(i>n) return;
   print2(i+1, n);
   cout << i << " ";
}

int main() {
    printl(1, 10);
    cout << endl;
    printr(10);
    cout << endl;
    print(5);
    cout << endl;
    print2(1, 5);

    return 0;
}