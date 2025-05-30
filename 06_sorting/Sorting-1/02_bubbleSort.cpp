# include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=1; i--){
        int isSwap = 0; // optimisation for best case O(n)
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isSwap++;
            }
        }
        if(!isSwap){
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    bubble_sort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}