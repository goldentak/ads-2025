#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq;
  
    int n ; cin >> n;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        pq.push(m);
    }
    
    while(pq.size() > 1){
        int h1 = pq.top();
        pq.pop();
        int h2 = pq.top();
        pq.pop();
        if(h1 > h2) pq.push(h1 - h2);
    }
    if(!pq.empty()) cout << pq.top();
    else cout << 0;
}