#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    deque<int> q;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        int m; cin >> m;
        bool added = false;
        for (auto it = q.rbegin(); it !=q.rend(); it++) {
            if(*it <= m) {
                ans.push_back(*it);
                added = true;
                break;
            }
        }
        if (!added) ans.push_back(-1);
        q.push_back(m);
    }
    
    for(int x : ans) cout << x << " ";
    return 0;
}