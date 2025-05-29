#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    // map<int, int> m;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        // m[arr[i]]++;
    }

    //precompute
    map<int, int> m;
    for(int i=0; i<n; i++){
        m[arr[i]]++;
    }

    // iterate in the map
    // for(auto it : m){
    //     cout << it.first << "->" << it.second << endl;
    // }

    int q;
    cin >> q;

    while (q--){
        int number;
        cin >> number;
        // fetch
        cout << m[number] << endl;
    }

    return 0;
}

// for string -> map<char, int>
// unordered -> TC => O(1) (best and avg) , O(n) (worst)