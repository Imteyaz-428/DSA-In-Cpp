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
// time comp :- O(n^2)
Node* build_bst(vector<int> &arr) {
    Node* root = NULL;
    for(int i: arr) {
        root = insert( root, i);
    }
    return root;
}
void inorder(Node* root) {
    if(root == NULL) {
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// Time comp :- O(n)
Node* built_bst(vector<int> &arr, int &i, int &bound) {
    if(i >= arr.size()  || arr[i] > bound)  {
        return NULL;
    }
    Node* root = new Node(arr[i++]);
    root->left = built_bst(arr, i, root->data);
    root->right = built_bst(arr, i , bound);
    return root;
}

int main() {
    vector<int> arr = {6,3,1,4,8,9};
    int i =0;
    int bound = INT_MAX;
    Node* root = built_bst(arr, i ,bound);
    inorder(root);
    cout << endl;
}