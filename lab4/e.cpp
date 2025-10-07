#include <bits/stdc++.h>
using namespace std;

struct Node {
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

void dfs(Node* root, int i, vector<int>& width){
    if(!root) return;
    
    if(i >= width.size()) width.push_back(0);
    
    width[i]++;
    
    dfs(root->left, i+1, width);
    dfs(root->right, i+1, width);
}

int main() {
    int n; cin >> n;
    Node* root = createNode(1);
    
    deque<Node*> dq;
    dq.push_back(root);
    vector<int> width;
    
    for(int i = 0; i < n; i++){
        int x, y, z; cin >> x >> y >> z;
        
        Node* newNode = createNode(y);
        dq.push_back(newNode);
        
        Node* parent = nullptr;
        for(auto it = dq.begin(); it != dq.end(); it++){
            if((*it)->data == x){
                parent = *it;
                break;
            }
        }
    
        if(parent){
            if(z) parent->right = newNode;
            else  parent->left = newNode;
        }
    }
    
    dfs(root, 0, width);
    
    cout << *max_element(width.begin(), width.end());
}
