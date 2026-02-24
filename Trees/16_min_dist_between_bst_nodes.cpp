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
        left = right = NULL;
    }
};
Node* build_tree(vector<int> &arr, int &idx) {
    idx++;
    if(arr[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(arr[idx]);
    root->left =build_tree(arr, idx);
    root->right =build_tree(arr, idx);
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

int min_distance(Node* root, Node* &prev, int &minm) {
    if(root == NULL ) {
        return minm;
    }
    int left = min_distance(root->left,prev, minm);
    
    if(prev != NULL) {
        minm =min(minm, (root->data - prev->data));
    }
    prev = root;
    int right = min_distance(root->right, prev, minm);
    return minm;
}
int main() {
    vector<int> arr = {83, 62,42, -1, 52,-1,-1,82,-1,-1, 88, -1,-1};
    int idx = -1;
    Node* root = build_tree(arr,idx);
    inorder(root);
    cout << endl;
    int minm = INT_MAX;
    Node* prev = NULL;
    int min = min_distance(root, prev, minm);
    cout << "Min :" << min << endl;
}