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

Node* searchNode(Node* root, int key){
    if(root == nullptr || root->data == key) return root;
    
    if(key < root->data) return searchNode(root->left, key);
    
    return searchNode(root->right, key);
}

void preOrderTraversal(Node* root){
    if(root != nullptr){
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main(){
    int n; cin >> n;
    
    Node* root = nullptr;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        root = insertNode(root, m);
    }
    int k; cin >> k;
    preOrderTraversal(searchNode(root, k));
    
    return 0;
}