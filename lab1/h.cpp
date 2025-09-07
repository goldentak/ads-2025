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
    if(isitprime(n)) cout << "YES";
    else cout << "NO";
    return 0;
}