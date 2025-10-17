#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(vector<int> &v, int i, int size){
    int largest = i;
    
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if(l < size && v[l] > v[largest]){
        largest = l;
    }
    if(r < size && v[r] > v[largest]){
        largest = r;
    }
    
    if(largest != i){
        swap(&v[i], &v[largest]);
        heapify(v, largest, size);
    }
}

void heapSort(vector<int> &v){
    int size = v.size();
    for(int i = size / 2 - 1; i >= 0; i--){
        heapify(v, i, size);
    }
    for(int i = size - 1; i > 0; i--){
        swap(&v[0], &v[i]);
        heapify(v, 0, i);
    }
}

void insert(vector<int> &v, int newNum){
    v.push_back(newNum);
    int curr = v.size() - 1;
    
    while(curr > 0){
        int parent = (curr - 1) / 2;
        
        if(v[curr] > v[parent]){
            swap(v[curr], v[parent]);
            curr = parent;
        } else {
            break;
        }
    }
}

void printArray(const vector<int> &v) {
    for (int ascii : v)
        cout << (char)ascii;
}

bool isVowel(char ch){
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main(){
    vector<int> vowels;
    vector<int> consonants;
    
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        char ch; cin >> ch;
        if(isVowel(ch)) insert(vowels, (int)ch);
        else insert(consonants, (int)ch);
    }
    
    heapSort(vowels);
    heapSort(consonants);
    
    printArray(vowels);
    printArray(consonants);
    
    return 0;
}