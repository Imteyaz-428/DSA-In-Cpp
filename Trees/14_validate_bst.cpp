#include <iostream> 
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;

    Node(int val) {
        data =val;
        right = left = NULL;
    }
};
Node* insert(Node* root, int i) {
    if(root == NULL) {
        return new Node(i);
    }
    if(root->data > i) {
        root->left = insert(root->left , i);

    } 
    if(root->data < i) {
        root->right = insert(root->right , i);
    }
    return root;

}

Node* Tree(vector<int> &vec) {
    Node* root = NULL;
    for(int i : vec) {
        root = insert(root,i);
    }
    return root;
}
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    
}

bool validate(Node* root, Node* min, Node* max) {
    if(root == NULL) {
        return true;
    }
    if(min != NULL && root->data <= min->data) {
        return false;
    }
    if(max != NULL && root->data >= max->data) {
        return false;
    }
    bool left = validate(root->left, min, root);
    bool right = validate(root->right, root, max);
    return left && right;
}

int main() {
    vector<int> vec = {8,2,1,10};
    Node* root = Tree(vec);
    inorder(root);
    
    cout << endl;
    Node* min = NULL;
    Node* max = NULL;
    cout << validate(root, min, max) << endl;
}