#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

bool isitprime(int a){
    if (a < 2) return false;
    for(int i = 2; i <= sqrt(a); i++){
       if(a % i == 0) return false; 
    }
    return true;
}

int main(){
    int n; cin >> n;
    int ans = 2;
    
    while(n){
        if(isitprime(ans)) n--;
        if(n) ans++;
    }
    cout << ans;
    return 0;
}