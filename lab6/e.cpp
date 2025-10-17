#include <bits/stdc++.h>
using namespace std;

int part(vector<int>& v, int low, int high){
    int pivot = v[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(pivot < v[j]){
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i+1], v[high]);
    return i+1;
}

void quick_sort(vector<int>& v, int low, int high){
    if(low < high){
        int pi = part(v, low, high);

        quick_sort(v, low, pi-1);
        quick_sort(v, pi+1, high);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int num;
            cin >> num;
            v[j][i] = num;
        }
    }

    for(int i = 0; i < m; i++){
        quick_sort(v[i], 0, n-1);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[j][i] << " ";
        }
        cout << endl;
    }


    return 0;
}