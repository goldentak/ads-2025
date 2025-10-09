#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<long long> pq;
  
    long long n, x; cin >> n >> x;
    long long sum = 0;
    
    for(long long i = 0; i < n; i++){
        long long m; cin >> m;
        pq.push(m);
    }
    
    while(x-- && !pq.empty()){
        long long temp = pq.top();
        pq.pop();
        sum += temp;
        if(temp - 1 != 0) pq.push(temp - 1);
    }
    
    cout << sum;
    return 0;
}