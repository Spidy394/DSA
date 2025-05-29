# include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    //precompute
    int hash[13] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        // fetch 
        cout << hash[number] << endl;
    }
    
    return 0;
}

// size of hash arr -> 10e6 inside main and 10e7 globally (int)

// but in case of bool hash arr -> 10e7 inside main and 10e8 gloabally 