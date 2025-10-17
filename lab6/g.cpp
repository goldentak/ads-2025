#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, string> curr;
    map<string, string> orig;

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        string old, news;
        cin >> old >> news;
        
        old = curr.count(old) ? curr[old] : old;
        
        orig[old] = news;
        curr[news] = old;
        
    }

    cout << orig.size() << endl;

    for(pair<string, string> i : orig){
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}