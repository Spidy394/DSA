// Find the largest element in an array (bonus smallest)

# include <bits/stdc++.h>
using namespace std;

// Optimal 
int largest(int arr[], int n){
    int largest = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }

    return largest;
}

int smallest(int arr[], int n){
    int smallest = INT_MAX;
    for(int i=1; i<n; i++){
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }

    return smallest;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << largest(arr, n) << endl;
    cout << smallest(arr, n);

    return 0;
}