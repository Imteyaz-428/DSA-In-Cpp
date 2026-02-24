#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

static int idx=-1;
Node* buildTree(vector<int> preorder) { 
    idx++;
    if(preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void topview(Node* root) {
    queue<pair<Node*,int>> q;
    map<int, int> m;

    q.push({root, 0});
    while(q.size()>0) {
        Node* Nodedata = q.front().first;
        int Horizontaldata = q.front().second;

        q.pop();
        if(m.find(Horizontaldata)== m.end()) {
            m[Horizontaldata] = Nodedata->data;
        }
        if(Nodedata->left != NULL) {
            q.push({Nodedata->left, Horizontaldata-1});


        }
        if(Nodedata->right != NULL) {
            q.push({Nodedata->right, Horizontaldata+1});
        }
    }
    for(auto i : m) {
        cout << i.second << " ";
    }
}



int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    topview(root);
    
    cout << endl;
}