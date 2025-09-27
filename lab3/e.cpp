#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(4));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> v[i][j];
        }
    }

    int low = 0, high = INT_MAX, ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int x1 = v[i][0], y1 = v[i][1];
            int x2 = v[i][2], y2 = v[i][3];
            if(x1 >= 0 && y1 >= 0 && x2 <= mid && y2 <= mid){
                cnt++;
            }
        }
        if(cnt >= k){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
    return 0;
}
