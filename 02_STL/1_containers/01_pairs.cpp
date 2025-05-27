# include <bits/stdc++.h>
using namespace std;

int main() {
    // Pairs are used to store two values together
    pair<int, int> p1 = {1,3};
    cout << p1.first << " " << p1.second << endl;

    pair<int, pair<int, int>> p2 = {1, {3,5}};
    cout << p2.first << " " << p2.second.second << " " << p2.second.first << endl;


    pair<int, int> arr[] = {{1,2}, {2,3}, {3,4}};
    cout << arr[0].first << " " << arr[0].second << endl;

    return 0;
}