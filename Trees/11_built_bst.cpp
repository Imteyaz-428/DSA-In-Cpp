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
        left = right = NULL;
    }
};
Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);
    }
    if(root->data > val) {
        root->left =insert(root->left, val);
    } else if(root->data < val) {
        root->right = insert(root->right, val);
    }
    return root;
}
Node* build_bst(vector<int> &arr) {
    int n = arr.size();
    Node* root = NULL;
    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}
void display(Node* root) {
    if(root == NULL ) {
        return;
    }
    
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}
bool search(Node* root, int val) {
    if(root == NULL ) {
        return false;
    }
    if(root->data == val) {
        return true;
    } else if(root->data > val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
    
}
Node* getInorder_successor(Node* root, int val)  {
    while(root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node* delete_node(Node* root, int val) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data > val) {
        root->left = delete_node(root->left, val);

    } else if(root->data < val) {
        root->right = delete_node(root->right, val);
    } else {
        //0 node or one onde 
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right ==NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp =getInorder_successor(root->right, val);
            root->data = temp->data;
            root->right =delete_node(root->right, temp->data);

        }
    }
    return root;
}
int main() {
    vector<int> arr = {2,9,4,8,5,1};
    Node* root = build_bst(arr);
    display(root);

    cout << endl;
    cout << search(root, 5);
    cout << endl;
    Node* root1 = delete_node(root, 4);
    display(root1);
    cout << endl;
}