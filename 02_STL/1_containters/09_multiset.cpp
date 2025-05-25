# include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    ms.erase(1); // all 1 erased 

    int cnt = ms.count(1);

    ms.erase(ms.find(1)); // only a single one erased 
    
    return 0;
}