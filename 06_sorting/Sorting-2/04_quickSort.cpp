# include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high){
            i++;
        }
        while(arr[j]>pivot && j>=low){
            j--;
        }

        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick(vector<int> &arr, int low, int high){
    if(low < high){
        int part = partition(arr, low, high);
        quick(arr, low, part-1);
        quick(arr, part+1, high);
    }
}

void quickSort(vector<int> &arr, int n){
    quick(arr, 0, n-1);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    quickSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}