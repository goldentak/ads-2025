#include <bits/stdc++.h>
using namespace std;

bool is_valid(const vector<long long>& v, int k, long long X) {
    int block = 1;
    long long sum = 0;

    for (long long i : v) {
        if (sum + i > X) {
            block++;
            sum = i;
        } else {
            sum += i;
        }
    }

    return block <= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);

    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        low = max(low, v[i]);
        high += v[i];
    }

    while (low < high) {
        long long mid = (low + high) / 2;

        if (is_valid(v, k, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low;

    return 0;
}
