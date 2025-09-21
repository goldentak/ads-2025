#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool binary_search(vector<int> v, int a){
    int left = 0;
    int right = v.size() - 1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(v[mid] == a) return true;
        else if(v[mid] < a) left = mid + 1;
        else right = mid - 1;
    }
    
    return false;
}

int main(){
    int n; cin >> n;
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        v.push_back(m);
    }
    
    int a; cin >> a;
    if(binary_search(v, a)) cout << "Yes";
    else cout << "No";
    
    return 0;
}