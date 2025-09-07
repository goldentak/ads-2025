#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

bool isitprime(int a){
    if (a < 2) return false;
    if (a == 2) return true;
    if (a % 2 == 0) return false;
    for (int i = 3; i <= sqrt(a); i += 2){
        if (a % i == 0) return false;
    }
    return true;
}
int main(){
    int n; cin >> n;
    int ans = 3, ind = 2;
    
    while(n){
        if(isitprime(ans)) {
            if(isitprime(ind)) n--;
            ind++;
        }
        if(n) ans++;
    }
    cout << ans;
    return 0;
}