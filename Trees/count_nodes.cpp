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
static int idx =-1;

Node* builttree(vector<int> preorder) {
    idx++;
    if(preorder[idx] == -1)  {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = builttree(preorder);
    root->right = builttree(preorder);
    return root;
}

int counts(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int left = counts(root->left);
    int right = counts(root->right);
    return (left+right) +1;
}

int sum(Node* root) {
    if(root == NULL) {
        return 0;
    }

    return sum(root->left) + sum(root->right) + root->data;
}
int main() {
    vector<int> arr= {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = builttree(arr);
    cout << counts(root) << endl;
    cout << sum(root) << endl;
    

}