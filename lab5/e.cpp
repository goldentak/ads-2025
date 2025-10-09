#include <bits/stdc++.h>
using namespace std;

int main() {
    long long sum = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    long long n, k; cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s == "print") cout << sum << endl;
        else if(s == "insert"){
            long long val; cin >> val;
            if(pq.size() < k){
                pq.push(val);
                sum += val;
            }
            else{
                if(pq.top() < val){
                    sum -= pq.top();
                    sum += val;
                    
                    pq.pop();
                    pq.push(val);
                }
            }
        }
    }
    
}