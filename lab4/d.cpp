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

int main(){
    int n; cin >> n;
    
    Node* root = nullptr;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        root = insertNode(root, m);
    }
    
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    
    while(!q.empty()){
        int size = q.size();
        int sum = 0;
        for(int i = 0; i < size; i++){
            Node* u = q.front(); q.pop();
            sum += u->data;
            
            if(u->left) q.push(u->left);
            if(u->right) q.push(u->right);
        }
        ans.push_back(sum);
    }
    
    cout << ans.size() << endl;
    for(int it : ans) cout << it << " ";
    
    return 0;
}