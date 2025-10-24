#include <bits/stdc++.h>
using namespace std;

void merge(vector<vector<int>>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<vector<int>> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0;
    int k = left;
    
    while (i < n1 && j < n2) {
        int sumL = accumulate(L[i].begin(), L[i].end(), 0);
        int sumR = accumulate(R[j].begin(), R[j].end(), 0);
        
        if (sumL > sumR) {
            arr[k] = L[i];
            i++;
        } else if (sumL < sumR) {
            arr[k] = R[j];
            j++;
        } else {
            int m = 0;
            while (m < L[i].size() && L[i][m] == R[j][m]) m++;
            if (m < L[i].size() && L[i][m] < R[j][m]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<vector<int>>& arr, int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n, m; cin >> n >> m;
    
    vector<vector<int>> v(n, vector<int>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    
    mergeSort(v, 0, v.size() - 1);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}