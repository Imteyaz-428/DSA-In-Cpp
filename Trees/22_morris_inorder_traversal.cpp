#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node( int val) {
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
    root->left = build_tree(arr, idx);
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
vector<int> morris_inorder(Node* root) {
    vector<int> ans;
    Node* IP = NULL;
    Node* curr = root;
    while(curr != NULL) {
        if(curr->left == NULL) {
            ans.push_back(curr->data);
            curr = curr->right;
        } else {
            IP = curr->left;
            while(IP->right != NULL && IP->right != curr ) {
                IP = IP->right;
            }
            if(IP->right == NULL) {
                IP->right = curr;// creating thread
                curr = curr->left;
            } else {
                IP->right = NULL; // destroy thread
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }

       
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int idx = -1;
    Node* root = build_tree(arr,idx);
    inorder(root);
    cout << endl;
    vector<int> ans = morris_inorder(root);
    for(int i: ans) {
        cout << i << " ";
    }
    cout << endl;
}