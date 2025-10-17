#include <bits/stdc++.h>
using namespace std;

bool quick_comp(const vector<pair<pair<string, string>, double>>& v, int j, pair<pair<string, string>, double> pivot){
    if(v[j].second != pivot.second)return v[j].second < pivot.second;
    if(v[j].first.first != pivot.first.first)return v[j].first.first < pivot.first.first;
    return v[j].first.second < pivot.first.second;
}

bool heap_comp(const pair<pair<string, string>, double>& a, const pair<pair<string, string>, double>& b){
    if(a.second != b.second)return a.second > b.second;
    if(a.first.first != b.first.first)return a.first.first > b.first.first;
    return a.first.second > b.first.second;
}

void heapify(vector<pair<pair<string, string>, double>>& v, int n, int i){
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if(l < n && heap_comp(v[l], v[largest]))
        largest = l;
    
    if(r < n && heap_comp(v[r], v[largest]))
        largest = r;
    
    if(i != largest){
        swap(v[i], v[largest]);

        heapify(v, n, largest);
    }
}

void heapsort(vector<pair<pair<string, string>, double>>& v){
    int n = v.size();

    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(v, n, i);
    }

    for(int i = n - 1; i > 0; i--){
        swap(v[0], v[i]);

        heapify(v, i, 0);
    }
}

int part(vector<pair<pair<string, string>, double>>& arr, int low, int high){
    pair<pair<string, string>, double> pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(quick_comp(arr, j, pivot)){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(vector<pair<pair<string, string>, double>>& arr, int low, int high){
    if(low < high){
        int pi = part(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    map<string, double> grades{
        {"A+", 4.0},
        {"A", 3.75},
        {"B+", 3.50},
        {"B", 3.0},
        {"C+", 2.50},
        {"C", 2.0},
        {"D+", 1.50},
        {"D", 1.0},
        {"F", 0.0}
    };

    vector<pair<pair<string, string>, double>> v;
    for(int i = 0; i < n; i++){
        string first_name, second_name;
        int m;
        cin >> first_name >> second_name >> m;
        double  g = 0.0, c = 0.0;  
        for(int j = 0; j < m; j++){
            string s;
            int k;
            cin >> s >> k;
            g += k * grades[s];
            c += k;
        }
        v.push_back({{first_name, second_name}, g / c});
    }

    heapsort(v);

    for(pair<pair<string, string>, double> i : v){
        cout << i.first.first + " " + i.first.second + " " << fixed << setprecision(3) << i.second * 1.0 << endl; 
    }
    return 0;
}