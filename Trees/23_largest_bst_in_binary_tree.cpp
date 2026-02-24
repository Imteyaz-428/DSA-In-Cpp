#include <iostream>
#include <vector>
#include <climits>
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

class INFO {
public:
    int minm;
    int maxm;
    int size;
    INFO(int min, int max, int sizes) {
        minm = min;
        maxm = max;
        size = sizes;
    }
};

Node* build_tree(vector<int> &arr, int &idx) {
    idx++;
    if(arr[idx] == -1) {
        return NULL;

    }
    Node* root = new Node(arr[idx]);
    root->left =build_tree(arr, idx);
    root->right = build_tree(arr, idx);
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

bool validate(Node* root, Node* min, Node* max) {
    if(root == NULL) {
        return true;
    }
    if(max != NULL && root->data > max->data) {
        return false;
    }
    if(min != NULL && root->data < min->data) {
        return false;
    }
    bool left = validate(root->left, min, root);
    bool right = validate(root->right, root, max);
    return left && right;
}

INFO helper(Node* root) {
    if(root == NULL) {
        return INFO(INT_MAX, INT_MIN, 0);
    }
    INFO left = helper(root->left);
    INFO right = helper(root->right);

    if(root->data > left.maxm && root->data < right.minm) {
        int currMin = min(root->data, left.minm);
        int currMax = max(root->data, right.maxm);
        int size = left.size + right.size+1;
        return INFO(currMin, currMax, size);
    }
    return INFO(INT_MIN, INT_MAX, max(left.size, right.size));
}
int largest(Node* root) {
    INFO info = helper(root);
    cout << info.maxm << endl;
    return info.size;

}

int main() {
    vector<int> arr = {10,5,1,-1,-1,8,-1,-1,15,-1,7,-1,-1};
    int idx = -1;
    Node* root =build_tree(arr, idx);
    inorder(root);
    cout << endl;
    cout << largest(root) << endl;
}