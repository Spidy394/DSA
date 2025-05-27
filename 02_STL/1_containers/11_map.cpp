# include <bits/stdc++.h>
using namespace std;

int main() {
    // works on "key: value" pairs
    // unique key
    // TC: log(n) 
    map<int, int> m;
    map<int , pair<int, int>> m1;
    map<pair<int, int>, int> m2;

    m[1] = 2; // { 1:2 }
    m.emplace(3, 1);
    m.insert({2, 4});

    m2[{4, 3}] = 10;

    for(auto it : m) {
        cout << it.first << " " << it.second << endl;
    }

    cout << m[1];
    cout << m[5];

    auto it = m.find(3);
    cout << (*it).second;
    
    return 0;
}

// Map derivaties 

// multimap => can store duplicate keys, map[key] can't use, 

// unordered_map => unique keys but not sorted, tc = O(1), wc = O(n)