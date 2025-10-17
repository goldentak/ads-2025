#include <bits/stdc++.h>
using namespace std;


void heapify(vector<char>& v, int n, int i){
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if(l < n && v[l] > v[largest])
        largest = l;
    
    if(r < n && v[r] > v[largest])
        largest = r;
    
    if(i != largest){
        swap(v[i], v[largest]);

        heapify(v, n, largest);
    }
}

void heapsort(vector<char>& v){
    int n = v.size();

    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(v, n, i);
    }

    for(int i = n - 1; i > 0; i--){
        swap(v[0], v[i]);

        heapify(v, i, 0);
    }
}

int main(){
    int n;
    cin >> n;
    vector<char> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    char ch;
    cin >> ch;
    heapsort(v);

    int i = 0;
    while(i < n-1){
        if(ch < v[i]){
            cout << v[i];
            break;
        }
        else if(ch == v[i]) {
            cout << v[i+1];
            break;
        }else{
            i++;
        }
    }
    if(i == n-1)cout << v[0];
    

    return 0;
}