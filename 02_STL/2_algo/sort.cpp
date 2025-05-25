# include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // they are same
    if(p1.first > p2.first) return true;
    return false;
}

void sort(){
    sort(a, a+n);
    sort(v.begin(), v.end());

    sort(a, a+n, greater<int>); // in decending order
    pair <int, int> a[] = { {1, 2}, {2, 1}, {4, 1}};


    // sort is according to second element
    // if second element is same, then sort 
    // it according to first element but in descenting 
    sort(a, a+n, comp);

    // {4, 1}, {2, 1}, {1, 2}


    int num = 7;
    int cnt = __builtin_popcount();

    long long num = 123453435;
    int cnt = __builtin_popcountll();

    string s = "123";
    sort(s.begin(), s.end());

    do {
        count << s << endl;
    } while(next_permutation(s.begin(), s.end()));


    int maxi = *max_element(a, a+n);

}

int main() {
   
    return 0;
}