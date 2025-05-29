# include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    // pecompute 
    int hash[26] = {0};
    for(int i =0; i<s.size(); i++){
        hash[s[i] - 'a']++;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        // fetch
        cout << hash[c - 'a'] << endl;
    }

    return 0;
}

/*
    for general case. i.e nature of char in string is unknown

    //precompute 
    int hash[256] = {0};
    for(int i=0; i<.sixe(); i++){
        hash[s[i]]++;
    // }

    // fetch
    cout << hash[c] << endl;

*/