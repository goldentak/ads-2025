#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int canStill(vector<int> v, int speed, int h){
    int totalh = 0;
    
    for(int bars : v){
        totalh += (bars + speed - 1) / speed;
    }
    return totalh <= h;
}

int main(){
    int n, h; cin >> n >> h;
    vector<int> v;
    
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        v.push_back(m);
    }
    
    int left = 1, right = *max_element(v.begin(), v.end()), res = right;
    
    while(left <= right){
        int mid = left + (right - left)/2;
        
        if(canStill(v, mid, h)){
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << res;
    return 0;
}