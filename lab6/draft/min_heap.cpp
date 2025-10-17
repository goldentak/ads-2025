#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(vector<int> &v, int i){
    int size = v.size();
    int smallest = i;
    
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if(l < size && v[l] < v[smallest]){
        smallest = l;
    }
    if(r < size && v[r] < v[smallest]){
        smallest = r;
    }
    
    if(smallest != i){
        swap(&v[i], &v[smallest]);
        heapify(v, smallest);
    }
}

void insert(vector<int> &v, int newNum){
    v.push_back(newNum);
    int curr = v.size() - 1;
    
    while(curr > 0){
        int parent = (curr - 1) / 2;
        
        if(v[curr] < v[parent]){
            swap(v[curr], v[parent]);
            curr = parent;
        } else {
            break;
        }
    }
}

void deleteNode(vector<int> &v, int num){
    int size = v.size();
    int i;
    for(i = 0; i < size; i++){
        if(num == v[i]) break;
    }
    
    swap(&v[i], &v[size - 1]);
    v.pop_back();
    
    size = v.size();
    if(i < size) heapify(v, i);
}

void printArray(const vector<int> &v) {
    for (int num : v)
        cout << num << " ";
    cout << "\n";
}

int main(){
    vector<int> heapTree;

    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    cout << "Min-Heap array: ";
    printArray(heapTree);

    deleteNode(heapTree, 4);
    cout << "After deleting an element: ";
    printArray(heapTree);

    return 0;
}
