
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n; cin >> n;

    vector<string> v;
    
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(!v.empty() && v[v.size() - 1] == s) continue;
        v.push_back(s);
    }
    
    cout << "All in all: "<< v.size() << endl << "Students:" << endl;
    
    for(int i = v.size() - 1; i >= 0; i--){
        cout << v[i] << endl;
    }
    
    return 0;
}
