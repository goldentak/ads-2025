#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> mp;
    
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        mp[k]++;
    }
    
    int max = INT_MIN;
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second > max) max = it->second;
    }
    
    for(auto it = mp.rbegin(); it != mp.rend(); it++){
        if(it->second == max) cout << it->first << " ";
    }
    return 0;
}
