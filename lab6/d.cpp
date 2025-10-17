#include <bits/stdc++.h>
using namespace std;

bool comp(const vector<int>& a, const vector<int>& b){
    if(a[2] != b[2])return a[2] > b[2];
    if(a[1] != b[1])return a[1] > b[1];
    return a[0] > b[0];
}


void heapify(vector<vector<int>>& v, int n, int i){
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if(l < n && comp(v[l], v[largest]))
        largest = l;
    
    if(r < n && comp(v[r], v[largest]))
        largest = r;
    
    if(i != largest){
        swap(v[i], v[largest]);

        heapify(v, n, largest);
    }
}

void heap_sort(vector<vector<int>>& v){
    int n = v.size();
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(v, n, i);
    }

    for(int i = n-1; i > 0; i--){
        swap(v[i], v[0]);
        heapify(v, i, 0);
    }
}


int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        string sum;
        for(char j : s){
            if(j == '-'){
                v[i].push_back(stoi(sum));
                sum = "";
            }
            else sum += j;
        }
        v[i].push_back(stoi(sum));
    }

    heap_sort(v);

    vector<vector<string>> res(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            if(v[i][j] < 10) res[i].push_back("0" + to_string(v[i][j]));
            else res[i].push_back(to_string(v[i][j]));
        }
    }

    for(vector<string> i : res){
        cout << i[0] + "-" + i[1] + "-" + i[2] << endl;
    }


    return 0;
}