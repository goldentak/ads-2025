#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, k;
    cin >> n >> k;

    vector<long> v(n), pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pref[i + 1] = pref[i] + v[i];
    }

    int min = INT_MAX;

    for (int i = 0; i < n + 1; i++) {
        int left = i + 1;
        int right = n;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (pref[mid] - pref[i] >= k) right = mid - 1;
            else left = mid + 1;
        }
        if (left <= n && pref[left] - pref[i] >= k)
            min = std::min(min, left - i);
    }
    cout << min;
    return 0;
}
