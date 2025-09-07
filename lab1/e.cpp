#include <iostream> 
#include <bits/stdc++.h>
using namespace std;


int main(){
    deque<int> b;
    deque<int> n;
    int moves = 0;
    
    for(int i = 0; i < 5; i++){
        int a; cin >> a;
        b.push_back(a);
    }
    for(int i = 0; i < 5; i++){
        int a; cin >> a;
        n.push_back(a);
    }
    
    while(moves < pow(10, 6)){
        int fb = b.front();
        int fn = n.front();
        
        b.pop_front();
        n.pop_front();
        
        bool borisWins = (fb == 0 && fn == 9) || (fb > fn && !(fb == 9 && fn == 0));
        
        if (borisWins) {
            b.push_back(fb);
            b.push_back(fn);
        } else {
            n.push_back(fb);
            n.push_back(fn);
        }
        
        moves++;
        
        if (b.empty()) { cout << "Nursik " << moves; return 0; }
        if (n.empty()) { cout << "Boris " << moves; return 0; }
    }
    cout << "blin nichya";
    return 0;
}