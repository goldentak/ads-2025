#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> enemies;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        enemies.push_back(m);
    }
    sort(enemies.begin(), enemies.end());

    int k; cin >> k;
    vector<int> v;
    for(int i = 0; i < k; i++){
        int m; cin >> m;
        v.push_back(m);
    }

    for(int i = 0; i < k; i++){
        int left = 0, right = n - 1;
        int pos = 0;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(enemies[mid] <= v[i]){
                pos = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        int sum = 0;
        for(int j = 0; j < pos; j++){
            sum += enemies[j];
        }
        cout << pos << " " << sum << endl;
    }

    return 0;
}
