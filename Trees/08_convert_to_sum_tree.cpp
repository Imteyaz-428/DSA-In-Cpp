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
static int idx = -1;
Node* buildBinaryTree(vector<int> preorder) {
    idx++;
    if(preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left=buildBinaryTree(preorder);
    root->right = buildBinaryTree(preorder);
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
int transform_tree(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftsum =transform_tree(root->left);
    int rightsum=transform_tree(root->right);
    root->data += leftsum + rightsum;
    return root->data;
}

int main() {
    vector<int> preorder = {1,2, -1,-1,3, 4, -1, -1, 5, -1,-1};
    Node* root = buildBinaryTree(preorder);
    preorders(root);
    cout << endl;
    cout << transform_tree(root) << endl;
    preorders(root);
    cout << endl;
    return 0;
}