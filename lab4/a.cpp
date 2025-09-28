#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node*  right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int data){
    if(root == nullptr) return createNode(data);
    
    if(data < root->data){
        root->left = insertNode(root->left, data);
    } else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    
    return root;
}

bool isPathToLeaf(Node* root, string s){
    Node* current = root;
    for(int i = 0; i < s.size(); i++){
        if(current == nullptr) return false;
        if(s[i] == 'L') current = current->left;
        else current = current->right;
    }
    return current != nullptr;
}


int main(){
    int n, k; cin >> n >> k;
    
    Node* root = nullptr;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        root = insertNode(root, m);
    }
    
    for(int i = 0; i < k; i++){
        string s; cin >> s;
        
        if(isPathToLeaf(root, s)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}