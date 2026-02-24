#include <iostream>
#include <vector>
#include <queue>

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
void display(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}
int max_width(Node* root) {
    if(root == NULL) {
        return -1;
    }
    queue<pair<Node* ,unsigned int>> q;
    q.push({root, 0});
    int maxwidth = 0;
    while(q.size() > 0) {
        int currsize = q.size();
        unsigned int firstIdx = q.front().second;
        unsigned int secondidx = q.back().second;
        maxwidth = max(maxwidth, (int)(secondidx - firstIdx +1));
        for(int i =0; i< currsize ; i++) {
            unsigned int idx = q.front().second;
            Node* curr = q.front().first;
            q.pop();
            if(curr->left != NULL) {
                q.push({curr->left, 2*idx + 1});
                
            }
            if(curr->right != NULL) {
                q.push({curr->right,2*idx + 2});
            }
        }
    }
    return maxwidth;
}
int main() {
    vector<int> arr = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int idx = -1;
    Node* root = build_tree(arr,idx);
    display(root);
    cout << endl;
    cout << max_width(root) << endl;

}
