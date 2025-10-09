#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ops = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    if(pq.top() >= k) {
        cout << 0;
        return 0;
    }

    while(pq.size() > 1) {
        long long low = pq.top();
        pq.pop();
        long long low2 = pq.top();
        pq.pop();

        long long low3 = low + 2 * low2;
        pq.push(low3);
        ops++;

        if(pq.top() >= k) {
            cout << ops;
            return 0;
        }
    }

    cout << -1;
    return 0;
}