// Find the second largest element of an array (bonus second smallest)

# include <bits/stdc++.h>
using namespace std;

int secondLargest(int a[], int n){
    int largest = a[0];
    int sLargest = -1;  // incase of -ve elements present in the arr take INT_MIN
    for(int i=1; i<n; i++){
        if(a[i] > largest){
            sLargest = largest;
            largest = a[i];
        } else if((a[i] < largest) && (a[i] > sLargest)){
            sLargest = a[i];
        }    
    }

    return sLargest;
}

int secondSmallest(int a[], int n){
    int smallest = a[0];
    int sSmallest = INT_MAX;
    for(int i=1; i<n; i++){
        if(a[i] < smallest){
            sSmallest = smallest;
            smallest = a[i];
        } else if((a[i] > smallest) && (a[i] < sSmallest)){
            sSmallest = a[i];
        }
    }

    return sSmallest; 
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << secondLargest(arr, n) << endl;
    cout << secondSmallest(arr, n);

    return 0;
}