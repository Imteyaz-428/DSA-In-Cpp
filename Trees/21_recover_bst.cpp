#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* insert(Node* root, int i) {
    if(root == NULL) {
        return new Node(i);
    }
    if(root->data > i) {
        root->left = insert(root->left, i);
    }
    if(root->data < i) {
        root->right = insert(root->right, i);
    }
    return root;
}
Node* Tree(vector<int> &arr) {
    Node* root = NULL;
    for(int i: arr) {
        root = insert(root, i);
    }
    return root;
}

Node* build_tree(vector<int> &arr, int &idx) {
    idx++;
    if(arr[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(arr[idx]);
    root->left = build_tree(arr, idx);
    root->right = build_tree(arr, idx);
    return root;
}
Node* First = NULL;
Node* Second = NULL;
Node* prevs = NULL;
// time comp -> O(n)
void recover_tree(Node* root) {
    if(root == NULL) {
        return ;
    }
    recover_tree(root->left);
    if(prevs != NULL && root->data < prevs->data) {
        if(First == NULL) {
            First = prevs;
        }
        Second = root;
    }
    prevs = root;
    recover_tree(root->right);
    
}

void inorder(Node* root) {
    if(root == NULL) {
        return ;
    }
    inorder(root->left) ;
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> arr = {6,3,1,-1,-1,8,-1,-1,4,-1,9,-1,-1};
    int idx = -1;
    Node* root = build_tree(arr, idx);
    inorder(root);
    cout << endl;
    recover_tree(root);
    swap(First->data, Second->data);
    inorder(root);
    cout << endl;
}