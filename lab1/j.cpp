#include <iostream> 
#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    deque<int> dq;
    while (cin >> s && s != "!") {
        
        if (s == "+") {
            int n; cin >> n;
            dq.push_front(n);
        } else if (s == "-") {
            int n; cin >> n;
            dq.push_back(n);
        } else if (s == "*") {
            if (dq.empty()) {
                cout << "error" << endl;
            } else {
                int f = dq.front();
                int b = dq.back();
                cout << f + b << endl;
                dq.pop_front();
                if (!dq.empty()) dq.pop_back();
            }
        }
    }
    return 0;
}   