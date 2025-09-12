#include <bits/stdc++.h>
using namespace std;

struct Node{
    string val;
    Node* next;
    Node(string x) : val(x), next(nullptr) {}
};

Node* addFront(Node* head, Node*& tail, const string& el){
    Node* n = new Node(el);
    n->next = head;
    head = n;
    if (!tail) tail = head;
    return head;
}

Node* addBack(Node* head, Node*& tail, const string& el){
    Node* n = new Node(el);
    if (!head){
        head = tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
    return head;
}

Node* eraseFront(Node* head, Node*& tail){
    if (!head) return nullptr;
    Node* old = head;
    head = head->next;
    if (!head) tail = nullptr;
    delete old;
    return head;
}

Node* eraseBack(Node* head, Node*& tail){
    if (!head) return nullptr;
    if (head == tail){
        delete head;
        return tail = nullptr;
    }
    Node* cur = head;
    while (cur->next != tail) cur = cur->next;
    delete tail;
    tail = cur;
    tail->next = nullptr;
    return head;
}

Node* clear(Node* head, Node*& tail){
    while (head){
        Node* t = head->next;
        delete head;
        head = t;
    }
    tail = nullptr;
    return head;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;
    Node* tail = nullptr;
    string s;

    while (cin >> s && s != "exit"){
        if (s == "add_front"){
            string el; cin >> el;
            head = addFront(head, tail, el);
            cout << "ok\n";
        }
        else if (s == "add_back"){
            string el; cin >> el;
            head = addBack(head, tail, el);
            cout << "ok\n";
        }
        else if (s == "erase_front"){
            if (head){
                cout << head->val << endl;
                head = eraseFront(head, tail);
            } else cout << "error\n";
        }
        else if (s == "erase_back"){
            if (head){
                cout << tail->val << endl;
                head = eraseBack(head, tail);
            } else cout << "error\n";
        }
        else if (s == "front"){
            if (head) cout << head->val << "\n";
            else cout << "error\n";
        }
        else if (s == "back"){
            if (tail) cout << tail->val << "\n";
            else cout << "error\n";
        }
        else if (s == "clear"){
            head = clear(head, tail);
            cout << "ok\n";
        }
        else {
            cout << "error\n";
        }
    }
    cout << "goodbye";
    head = clear(head, tail);
    return 0;
}
