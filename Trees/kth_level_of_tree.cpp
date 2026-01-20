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
        left = right= NULL;
    }
};
static int idx= -1;
Node* buildTree(vector<int> preorder) {
    idx++;
    if(preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left =buildTree(preorder);
    root->right =buildTree(preorder);
    return root;
}
void preorders(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorders(root->left);
    preorders(root->right);
}
void Kthorder(Node* root, int k) {
    if(root == NULL) {
        return;
    }
    if(k == 1) {
        cout << root->data << " ";
        return;
    }
    Kthorder(root->left, k-1);
    Kthorder(root->right, k-1) ;
}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    preorders(root);
    cout << endl;
    Kthorder(root, 3);
    cout << endl;
}