#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x = 0) : val(x), next(nullptr) {}
};

int findMaxSum(int n, Node* head){
    int max = INT_MIN;
    Node* current1 = head;
    for(int i = 0; i < n; i++){
        int sum = 0;
        Node* current2 = current1;
        
        for(int j = i; j < n; j++){
            sum += current2->val;
            current2 = current2->next;
            if(sum > max) max = sum;
        }
        
        current1 = current1->next;
        
    }
    return max;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if(!(cin >> n)) return 0;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        Node* cur = new Node(x);
        if (!head){
            head = tail = cur;
        } else {
            tail->next = cur;
            tail = cur;
        }
    }

    cout << findMaxSum(n, head) << "\n";
    return 0;
}
