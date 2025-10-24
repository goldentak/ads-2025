#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<string, double>>& arr, long long left, long long mid, long long right){
    long long n1 = mid - left + 1;
    long long n2 = right - mid;
    
    vector<pair<string, double>> L(n1), R(n2);
    
    for(long long i = 0; i < n1; i++) L[i] = arr[left + i];
    for(long long j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    long long i = 0, j = 0;
    long long k = left;
    
    while(i < n1 && j < n2){
        if(L[i].second <= R[j].second){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<string, double>>& arr, long long left, long long right){
    if(left >= right) return;
    
    long long mid = left + (right - left) / 2;
    
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

map<string, double> grade_map;

int main() {
    grade_map["A+"] = 4.00;
    grade_map["A"] = 3.75;
    grade_map["B+"] = 3.50;
    grade_map["B"] = 3.00;
    grade_map["C+"] = 2.50;
    grade_map["C"] = 2.00;
    grade_map["D+"] = 1.50;
    grade_map["D"] = 1.00;
    grade_map["F"] = 0.00;
    
    long long n; cin >> n;
    vector<pair<string, double>> v;
    for(long long i = 0; i < n; i++){
        string f, l; cin >> l >> f;
        long long m; cin >> m;
        double sum = 0;
        long long sumEcts = 0;
        for(long long j = 0; j < m; j++){
            string grade;
            long long ects;
            cin >> grade >> ects;
            sum += grade_map[grade] * ects;
            sumEcts += ects;
        }
        v.push_back({l + " " + f, sum / sumEcts});
    }
    
    mergeSort(v, 0, v.size() - 1);
    
    cout << fixed << setprecision(3);
    for(long long i = 0; i < n; i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    
    return 0;
}