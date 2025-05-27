# include <bits/stdc++.h>
using namespace std;

int main() {
    // the largest element stays at the top
    // max heap
    priority_queue<int> pq;

    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5 , 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top() << endl; // 10

    pq.pop();
    cout << pq.top() << endl; // 8
    // size swap empty same as stack o queue


    // Minimun Heap
    priority_queue<int , vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2, 5}
    pq.push(8); // {2, 5 , 8}
    pq.emplace(10); // {2, 5, 8, 10}
    cout << pq.top() << endl; // 2

    return 0;
}

/*
    push -> Log(n)
    top -> O(1)
    pop -> Log(n)

*/