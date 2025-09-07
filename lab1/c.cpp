#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    string t; cin >> t;
    for(auto it = s.begin(); it != s.end();){
        if(*it == '#'){
            if(it != s.begin()){
                it = s.erase(it - 1, it + 1);
            } else {
                it = s.erase(it);
            }
        }
        else {
            it++;
        }
    }

    for(auto it = t.begin(); it != t.end();){
        if(*it == '#'){
            if(it != t.begin()){
                it = t.erase(it - 1, it + 1);
            } else {
                it = t.erase(it);
            }
        }
        else {
            it++;
        }
    }

    if(s == t) cout << "Yes";
    else cout << "No";
    return 0;
}