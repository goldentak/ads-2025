#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n; cin >> n;
    string str; cin >> str;
    queue<int> s, k;
    for(int i = 0; i < n; i++){
        if(str[i] == 'S') s.push(i);
        else k.push(i);
    }
    
    while(true){
        if(s.empty()){cout << "KATSURAGI"; return 0;}
        if(k.empty()){cout << "SAKAYANAGI"; return 0;}

        int si = s.front(); s.pop();
        int ki = k.front(); k.pop();
        
        if(si < ki) s.push(si + n);
        else k.push(ki + n);
    }
}