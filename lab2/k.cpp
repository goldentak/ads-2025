#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n; cin >> n;
    vector<char> v;
    queue<char> q;
    
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        for(int j = 0; j < m; j++){
            char ch; cin >> ch;
            if(j == 0){
                v.push_back(ch);
            }
            else if(v[v.size() - 1] == ch){
                v.push_back(q.front());
                q.pop();
            }
            
            q.push(ch);
            cout << v[v.size() - 1] << " ";
        }
        cout << endl;
    }
    return 0;
}
