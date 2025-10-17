#include <bits/stdc++.h>
using namespace std;

int part(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void qSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pi = part(arr, low, high);
        qSort(arr, low, pi - 1);
        qSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> points(n);

    for(int i = 0; i < n; i++) {
        cin >> points[i];
    }

    qSort(points, 0, n - 1);

    int min_diff = INT_MAX;
    for(int i = 1; i < n; i++) {
        min_diff = min(min_diff, points[i] - points[i - 1]);
    }

    for(int i = 1; i < n; i++) {
        if(points[i] - points[i - 1] == min_diff) {
            cout << points[i - 1] << " " << points[i] << " ";
        }
    }

    return 0;
}