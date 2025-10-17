#include <bits/stdc++.h>
using namespace std;

int part(vector<long long>& arr, int low, int high){
    long long pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(vector<long long>& arr, int low, int high){
    if(low < high){
        int pi = part(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    string s;
    cin >> s;
    
    set<char> unique_chars(s.begin(), s.end());
    
    string result(unique_chars.begin(), unique_chars.end());
    
    cout << result << endl;

    return 0;
}