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

    if(data < root->data) root->left = insertNode(root->left, data);
    else if(data > root->data) root->right = insertNode(root->right, data);
    return root;
}

int maxDepth(Node* root){
    if(!root) return 0;
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return max(leftDepth, rightDepth) + 1;
}

int maxdep = 0;
int maxDepths(Node* root){
    if(!root) return 0;
    
    int leftDepth = maxDepths(root->left);
    int rightDepth = maxDepths(root->right);
    
    maxdep = max(maxdep, leftDepth + rightDepth);
    
    return max(leftDepth, rightDepth) + 1;
}


int main (){
    int n; cin >> n;

    Node* root = nullptr;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        root = insertNode(root, m);
    }
    
    maxDepths(root);
    cout << maxdep + 1;
    return 0;  
}
