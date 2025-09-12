#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int x) : val(x), next(nullptr) {}
};

int findNearest(Node* head, int target) {
    int minDiff = INT_MAX;
    int index = -1;
    int currentIndex = 0;

    Node* current = head;
    while (current != nullptr) {
        int diff = abs(current->val - target);
        if (diff == 0) return currentIndex; 
        if (diff < minDiff) {
            minDiff = diff;
            index = currentIndex;
        }
        current = current->next;
        currentIndex++;
    }
    return index;
}

int main() {
    int n; cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
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

    int target; cin >> target;
    
    int index = findNearest(head, target);
    cout << index << endl;
    
    return 0;
}
