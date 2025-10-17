#include <bits/stdc++.h>
using namespace std;

int part(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pi = part(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> f1(n), f2(m);

    for(int i = 0; i < n; i++){
        cin >> f1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> f2[i];
    }

    quickSort(f1, 0, n-1);
    quickSort(f2, 0, m-1);

    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(f1[i] == f2[j]){
            cout << f1[i] << " ";
            i++;
            j++;
        }else if(f1[i] < f2[j]){
            i++;
        }
        else j++;
    }

    return 0;
}