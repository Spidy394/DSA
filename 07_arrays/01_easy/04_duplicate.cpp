// Remove Duplicates from Sorted Array

# include <bits/stdc++.h>
using namespace std;

int removeDuplicate(int a[], int n){
    int index = 0;
        for(int j=1; j<n; j++){
            if(a[j] != a[index]){
                a[index + 1] = a[j];
                index++;
            }
        }
        return (index+1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int j = removeDuplicate(arr, n);
    for(int i=0; i<j; i++){
        cout << arr[i] << " ";
    }

    return 0;
}