#include <bits/stdc++.h>
using namespace std;

void solve(const vector<int>& v, int l, int r, vector<int>& res) {
    if (l > r) return;
    int m = (l + r) / 2;

    res.push_back(v[m]);
    solve(v, l, m - 1, res);
    solve(v, m + 1, r, res);
}

int main() {
    int num;
    cin >> num;
    int n = (1 << num) - 1;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> result;
    solve(v, 0, n - 1, result);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}