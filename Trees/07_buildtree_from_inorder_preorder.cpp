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

Node* built_tree(vector<int>& arr ,int &idx) {
    idx++;
    if(arr[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(arr[idx]);
    root->left = built_tree(arr, idx);
    root->right = built_tree(arr, idx);
    return root;

}
void display(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    display(root->left);
    display(root->right);
    
}

int search(vector<int> &inorder, int left, int right , int num) {
    for(int i=left; i<=right; i++) {
        if(inorder[i] == num) {
            return i;
        }
    }
    return -1;
}
static int preidx = 0;
Node* build_tree(vector<int> &inorder, vector<int> &preorder, int left, int right) {
    if(left > right) {
        return NULL;
    }
    Node* root = new Node(preorder[preidx]);
    int idx = search(inorder, left, right, preorder[preidx]);
    preidx++;
    root->left = build_tree(inorder, preorder, left, idx-1 );
    root->right = build_tree(inorder, preorder, idx+1, right);
    return root;
}
int main() {
    
    vector<int> preorder = {1, 2, 4, 5, 3};
    vector<int> inorder =  {4, 2, 5, 1, 3};
    int left = 0;
    int right = inorder.size() -1;
    Node* root3 = build_tree(inorder, preorder,left, right );
    display(root3);
    cout << endl;
 
}