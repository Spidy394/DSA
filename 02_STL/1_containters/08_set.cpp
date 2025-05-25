# include <bits/stdc++.h>
using namespace std;

int main() {
    // set => "sorted" and "unique"
    set<int> st;
    st.insert(1); // {1}
    st.emplace(2); // {1, 2}
    st.insert(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.insert(3); // {1, 2, 3, 4}

    // begin() end() rbegin() rend() size() empty() swap() are same like before

    auto it = st.find(3);
    auto it = st.find(6); // points to after set.end()
    st.erase(5);

    int cnt = st.count(1);

    auto it = st.find(3);
    st.erase(it);

    auto it = st.find(3);
    st.erase(it);

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // {1, 4, 5} [first, last]

    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

    return 0;
}