#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
};

Node* createNode(int data){
  Node* newNode = new Node();
  newNode->data = data;
  newNode->left = newNode->right = nullptr;
  return newNode;
}

Node* insertNode(Node* root, int data){
  if(root == nullptr) return createNode(data);

  if(data > root->data) root->right = insertNode(root->right, data);
  if(data < root->data) root->left = insertNode(root->left, data);
  
  return root;
}

int sum = 0;
void inOrderTraversal(Node* root){
  if(root == nullptr) return;

  inOrderTraversal(root->right);
  sum += root->data;
  cout << sum << " ";
  inOrderTraversal(root->left);
}

int main(){
  int n; cin >> n;
  Node* root = nullptr;

  for(int i = 0; i < n; i++){
    int m; cin >> m;
    root = insertNode(root, m);
  }
  
  inOrderTraversal(root);
  return 0;
}