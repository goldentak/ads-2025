
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    
    Node(int x) : val(x), next(nullptr) {}
};

int main(){ 
    int n; cin >> n;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        
        Node* newNode = new Node(m);
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    int num, pos; cin >> num >> pos;
    
    Node* current = head;
    Node* newNum = new Node(num);
    Node* res;
    if(pos) {
        for(int i = 0; i < pos - 1; i++) current = current->next;
        Node* temp = current->next;
        current->next = newNum;
        newNum->next = temp;
        res = head;
    }
    else {
        newNum->next = head;
        res = newNum;
    }
    
    while(res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    
    return 0;
}
