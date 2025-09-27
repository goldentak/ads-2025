#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int flight(int a){
    int f = 0;
    for(int i = 0; i < v.size(); i++){
        f += (v[i] + a - 1) / a;
    }
    return f;
}

int main() {
    long n, f; cin >> n >> f;
    
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        v.push_back(m);
    }
    
    auto max_iter = max_element(v.begin(), v.end());
    int left = 1, right = *max_iter, ans = 0;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        int flights_count = flight(mid);

        if(flights_count <= f){
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans;
    return 0;
}
