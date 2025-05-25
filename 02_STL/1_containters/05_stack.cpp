# include <bits/stdc++.h>
using namespace std;

int main() {
    // stack => LIFO (Last In First Out) | O(1)
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.emplace(5); // {5, 2, 1}

    cout << st.top() << endl; // 5 

    st.pop(); // {2, 1}
    cout << st.top() << endl; // 2

    cout << st.size() << endl; // 2

    cout << st.empty() << endl; // gives 1 or 0 (true or false)

    stack<int> st1, st2;
    st1.swap(st2); 
    
    return 0;
}