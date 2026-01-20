#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node(int val) {
        data = val;
        right = left = NULL;
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

void inorder(Node* root)  {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


bool search(Node* root, int key) {
    if(root == NULL) {
        return false;
    }
    if(root->data == key ) {
        return true;
    }
    if(root->data < key) {
        return search(root->right, key);
    } else {
        return search(root->left, key);
    }
}
Node* getinordersuccessor(Node* root) {
    while(root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root, int key) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data > key) {
        root->left = deleteNode(root->left, key);
    } else if(root->data < key) {
        root->right = deleteNode(root->right, key);
    } else {
        // key is matched
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* IS = getinordersuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);
        }
    }
    return root;
}

int main () {
    vector<int> arr = {3,2,1,5,6,4};
    Node* root =build_tree(arr);
    inorder(root);
    cout << endl;
    cout << search(root, 9) << endl;
    deleteNode(root, 5);
    inorder(root);
    cout << endl;
}