# include <bits/stdc++.h>
using namespace std;

int main() {
    // Vectors are dynamic arrays i.e they can grow and shrink in size
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2); // emplace_back is faster than push_back
    cout << v[0] << " " << v[1] << endl;

    // difference in syntax between push_back and emplace_back in vector of pairs
    vector<pair<int, int>> vp;
    vp.push_back({1, 2});
    vp.emplace_back(3, 4); 


    vector<int> v1(5, 10); // vector of size 5 with all elements as 10
    vector<int> v2(v1); // copy of v1


    // Iterating over a vector
    vector<int>::iterator it = v1.begin(); // iterator is a pointer to the first element of the vector 
    it++;
    cout << *it << endl;

    vector<int>::iterator it = v1.end(); // points to a position after the last element of the vector
    // rend => reverse end, rbegin => reverse begin

    cout << v1[0] << " " << v1.at(1) << endl;
    cout << v1.back() << endl; // last element
    cout << v1.front() << endl; // first element


    for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }

    // auto => assings datatype automatically
    for(auto it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }

    // for each loop  
    for(auto it : v1) {
        cout << it << " ";
    }

    // deleting elements from a vector
    v1.erase(v1.begin() + 1); // erases the element at index 1
    v1.erase(v1.begin() + 1, v1.begin() + 3); // erases elements from index 1 to 2
    v1.clear(); // erases all elements


    // inserting elements in a vector
    v1.insert(v1.begin() + 1, 5); // inserts 5 at index 1
    v1.insert(v1.begin() + 1, 3, 10); // inserts 10, 10, 10 at index 1

    cout << v1.size() << endl; // size of the vector
    v1.pop_back(); // remove the last element

    v1.swap(v2);

    cout << v1.empty(); // erase the entire vector

    return 0;
}