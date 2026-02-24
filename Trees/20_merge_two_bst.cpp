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
        left =right = NULL;
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
        root->right  = insert(root->right, i);
    }
    return root;
}
Node* build_bst(vector<int> &arr) {
    Node* root = NULL;
    for(int i : arr) {
        root = insert(root, i);
    }
    return root;
}
void inorder(Node* root, vector<int> &arr) {
    if(root == NULL) {
        return ;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
Node* balanced_bst(vector<int> &arr, int st, int end) {
    if(st > end) {
        return NULL;
    }
    int mid = st + (end -st)/2;
    Node* root = new Node(arr[mid]);
    root->left =balanced_bst(arr, st, mid-1);
    root->right = balanced_bst(arr, mid+1, end);
    return root;
}
Node* merge(Node* root1, Node* root2) {
    vector<int> arr1;
    vector<int> arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);
    int i=0;
    int j =0;
    vector<int> temp;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] > arr2[j]) {
            temp.push_back(arr2[j]);
            j++;
        } else {
            temp.push_back(arr1[i]);
            i++;
        }
       
    }
    while(i < arr1.size()) {
        temp.push_back(arr1[i]);
        i++;
    }
    while(j < arr2.size()) {
        temp.push_back(arr2[j]);
        j++;
    }
    int st =0;
    int end  = temp.size() -1;
    Node* root3 = balanced_bst(temp,st, end);
    return root3;
}
void inorder_traversal(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}


int main() {
    vector<int> arr = {8,2,1,10};
    vector<int> arr2 = {5,3,0};
    Node* root1 = build_bst(arr);
    Node* root2 = build_bst(arr2);
    Node* root3 = merge(root1, root2);
    inorder_traversal(root3);
    cout << endl;
}