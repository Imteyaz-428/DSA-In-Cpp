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
int height(Node* root) {
    if(root == NULL) {
        return 0;
    }
    
    return max(height(root->left), height(root->right))+1;


}
static int ans = 0;

int heights(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftht = heights(root->left);
    int rightht = heights(root->right);
    ans = max(leftht+rightht, ans); // this is for calculating diameter as well in O(n) time complexity
    return max(leftht, rightht)+1;
   
}

// time complexity :- O(n^2)
int diameter(Node* root)  {
    if(root == NULL) {
        return 0;
    }
    int left = diameter(root->left);
    int right = diameter(root->right);
    int curr = height(root->left) + height(root->right);
    return max(curr,max(left, right));
}


int main() {
    vector<int> arr= {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = builttree(arr);
    cout << height(root) << endl;
    cout << diameter(root) << endl;
    heights(root);
    cout << ans << endl;

}