# include <bits/stdc++.h>
using namespace std;

void recBubbleSort(vector<int> &arr, int n){
    if (n == 1) return;
    int count = 0;

    for(int i=0; i<n-i; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            count++;
        }
    }
    if (count == 0) return;

    recBubbleSort(arr, n-1);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    recBubbleSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}