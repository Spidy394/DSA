# include <bits/stdc++.h>
using namespace std;
// method - 1
void rev(int l, int r, int arr[]){
    if(l>=r) return;
    swap(arr[l], arr[r]);
    rev(l+1, r-1, arr);
}

// method - 2
void reverse(int i, int n, int arr[]){
    if(i>=n/2) return; // n is the size of array, not the last index
    swap(arr[i], arr[n-i-1]);
    reverse(i+1, n, arr);
}


int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    rev(0, 4, arr1);
    for(int i=0; i<5; i++) cout << arr1[i] << " ";
    cout << endl;
    
    int arr2[] = {2, 4, 6, 8, 10};
    reverse(0, 5, arr2);
    for(int i=0; i<5; i++) cout << arr2[i] << " ";

    return 0;
}