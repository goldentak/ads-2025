#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	} 
};

Node* getMin(Node* root) {
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == nullptr) {
		return new Node(data);
	} else if (root->data >= data) {
		if (root->left == nullptr) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data < data) {
		if (root->right == nullptr) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == nullptr) {
		return nullptr;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
		if (root->left == nullptr && root->right == nullptr) {
			delete root;
			return nullptr;
		} else if (root->right == nullptr) {
			Node* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == nullptr) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else {
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

Node* find(Node* root, int x) {
	if (root == nullptr) {
		return nullptr;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}

int count(Node* root, int m){
    if(!root) return 0;
    
    int sum = 0;
    
    sum += count(root->left, m);
    sum += count(root->right, m);
    
    if(root->data == m) sum++;
    
    return sum;
}

int main(){
    int n; cin >> n;
    Node* root = nullptr;
    
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int m; cin >> m;
        
        if(s == "insert") root = add(root, m);
        else if(s == "cnt") cout << count(root, m) << endl;
        else if(s == "delete") root = deleteNode(root, m);
    }
}