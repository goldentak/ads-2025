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

void inorderTraversal(Node* root){
    if(root != nullptr){
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preOrderTraversal(Node* root){
    if(root != nullptr){
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

Node* searchNode(Node* root, int key){
    if(root == nullptr || root->data == key) return root;
    
    if(root->data < key) searchNode(root->right, key);
    
    return searchNode(root->left, key);
}

Node* minValueNode(Node* node){
    Node* current = node;
    while(current && current->left != nullptr){
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int data){
    if(root == nullptr) return root;
    
    if(data < root->data) root->left = deleteNode(root->left, data);
    else if(data > root->data) root->right = deleteNode(root->right, data);
    else {
        if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
    
        root->data = temp->data;
    
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}











