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
    for( int i : arr) {
        root = insert(root, i);
    }
    return root;
}
void  inorder(Node* root,vector<int> &arr) {
    
    if(root == NULL) {

        return ;
    }
    inorder(root->left, arr);
    cout << root->data << " ";
    arr.push_back(root->data);
    inorder(root->right, arr);
    

}
Node* build(vector<int> &arr, int st, int end) {
    if(st > end) {
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node* root = new Node(arr[mid]);
    root->left = build(arr, st, mid-1);
    root->right = build(arr, mid+1, end);
    return root;
}

int main() {
    vector<int> arr = {1,3,43,21,98};
    Node* root  =Tree(arr);
    vector<int> vec ;
    inorder(root,vec);
    cout << endl;
    cout << vec[3] << endl;
    int st = 0;
    int end = vec.size() -1;
    Node* root1 = build(vec, st, end);
    vector<int> num;
    inorder(root1, num);
}
