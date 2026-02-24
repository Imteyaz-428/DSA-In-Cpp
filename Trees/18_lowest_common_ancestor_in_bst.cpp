#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right ;
    Node(int val) {
        data = val;
        right = left = NULL;
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
    for(int i: arr) {
        root = insert(root, i);
    }
    return root;
}
void inorder(Node* root ) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    
}
Node* lca(Node* root, Node* p, Node* q) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == p->data || root->data == q->data) {
        return root;
    }
    if(root->data > p->data && root->data > q->data) {
        return lca(root->left, p, q);
    } else if(root->data < p->data && root->data < q->data) {
        return lca(root->right, p, q);
    } else {
        return root;
    }
    
}

int main() {
    vector<int> arr = {2,3,9,8,7,6,5,4};
    Node* p = new Node(2);
    Node* q = new Node(8);
    Node* root = Tree(arr);
    inorder(root);
    Node* roo1 = lca(root, p, q);
    cout << endl;
    cout << roo1->data << endl;
    cout << endl;

}