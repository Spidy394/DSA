# include <bits/stdc++.h>
using namespace std;

int main() {
    // queue => FIFO (First In First Out) | O(1)
    queue<int> q;
    q.push(1); // {1}
    q.push(3); // {1, 3}
    q.emplace(5); // {1, 3, 5}

    q.back() += 7; 

    cout << q.back() << endl; // 12
    cout << q.front() << endl; // 1

    q.pop();

    cout << q.front(); // 3

    // size swap empty same as stack
    return 0;
}