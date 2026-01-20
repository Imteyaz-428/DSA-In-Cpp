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
Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);

    }
    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right,val);
    }
    return root;

}


Node* build_tree(vector<int> arr) {
    Node* root = NULL;
    for(int val : arr) {
        root = insert(root, val);
    }
    return root;

}

void traverse(Node* root) {
    if(root == NULL) {
        return;
    }
    traverse(root->left);
    cout << root->data << " ";
    traverse(root->right);
}
void inorder(Node* root, vector<int> &arr) {
    if(root == NULL) {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);

}
Node* balanced_bst(vector<int> &temp, int st, int end){
    if(st > end) {
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node* newNode = new Node(temp[mid]);
    newNode->left = balanced_bst(temp, st, mid-1);
    newNode->right = balanced_bst(temp, mid+1, end);
    return newNode;

}

Node* merge(Node* root1, Node* root2){
    vector<int> arr1;
    vector<int> arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);
    vector<int> temp;
    int i =0;
    int j =0;
    while(i< arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            temp.push_back(arr1[i++]);
        } else {
            temp.push_back(arr2[j++]);
        }
    }
    while(i<arr1.size()) {
        temp.push_back(arr1[i++]);
    }
    while(j<arr2.size()) {
        temp.push_back(arr2[j++]);
    }
    int st =0;
    int end = temp.size()-1;
    Node* root = balanced_bst(temp, st, end);
    return root;
}

int main() {
    vector<int> arr1 ={8,2,1,10};
    vector<int> arr2 = {5,3,0};
    Node* root1 = build_tree(arr1);
    Node* root2 = build_tree(arr2);
   
    Node* root = merge(root1, root2);
    traverse(root);
    cout << endl;
}