#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left =right = NULL;
    }
};
Node* insert(Node* root ,int i) {
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
    for(int i : arr) {
        root = insert(root,i);
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
int kth_smallest(Node* root, int k, int &count) {
    if(root == NULL) {
        return -1;
    }
    int left = kth_smallest(root->left, k, count);
    if(left != -1) {
        return left;
    }
    count++;
    if(count == k) {
        return root->data;
    }
    
    return kth_smallest(root->right,k, count);
   
}

int main() {
    vector<int> arr = {2,4,8,1,9,11};
    Node* root = Tree(arr);
    inorder(root);
    cout << endl;
    int count = 0;
    cout << kth_smallest(root, 3,count) << endl;
}