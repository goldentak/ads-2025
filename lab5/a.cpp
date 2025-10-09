#include <bits/stdc++.h>
using namespace std;

int main() {
    long long sum = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
  
    int n ; cin >> n;
    for(int i = 0; i < n; i++){
        long long m; cin >> m;
        pq.push(m);
    }
    
    while(pq.size() > 1){
        long long temp = pq.top();
        pq.pop();
        
        temp += pq.top();
        pq.pop();
        pq.push(temp);
        
        sum += temp;
    }
    
    cout << sum;
}