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
Node* build_bst(vector<int> &arr) {
    Node* root = NULL;
    for(int i: arr) {
        root = insert(root, i);
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
Node* rightMostLeftSubtree(Node* root) {
    Node* ans;
    while(root != NULL) {
        ans = root;
        root = root->right;
    }
    return ans;
}
Node* leftMostRightSubtree(Node* root) {
    Node* ans;
    while(root != NULL) {
        ans = root;
        root = root->left;
    }
    return ans;
}
vector<int> predAndSucc(Node* root, int key) {
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;
    while(curr != NULL) {
        if(curr->data > key) {
            succ = curr;
            curr = curr->left;
        } else if(curr->data < key) {
            pred = curr;
            curr = curr->right;
        } else {
            // inorder pred
            if(curr->left != NULL) {
                pred = rightMostLeftSubtree(curr->left);
            }

            //inorder succ 
            if(curr->right != NULL) {
                succ = leftMostRightSubtree(curr->right);
            }
            break;
        }
    }
    return {pred->data, succ->data};
}

int main() {
    vector<int> vec = {1,5,4,9,8,7,6};
    Node* root = build_bst(vec);
    inorder(root);
    cout << endl;
    vector<int> arr = predAndSucc(root, 6);
    cout << "pred :" << arr[0] << " " << " succ: " << arr[1] << endl;


}