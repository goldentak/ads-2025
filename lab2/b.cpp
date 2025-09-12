#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string val;
    Node* next;

    Node(string x) : val(x), next(nullptr) {}
};

Node* shiftList(Node* head, int k){
    if (head == nullptr || k == 0) return head;
    
    Node* temp = head;
    int length = 1;
    
    while(temp->next != nullptr){
        temp = temp->next;
        length++;
    }
    k = k % length;
    if (k == 0) return head;
    
    temp->next = head;
    
    Node* newTail = head;
    for(int i = 0; i < k - 1; i++){
        newTail = newTail->next;
    }
    
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    
    return newHead;
}

int main() {
    int n, k; 
    cin >> n; cin >> k;
    
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        string word; cin >> word;
        Node* newNode = new Node(word);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    head = shiftList(head, k);
    
    Node* current = head;
    while(current != nullptr){
        cout << current->val << " ";
        current = current->next;
    }
    return 0;
}
