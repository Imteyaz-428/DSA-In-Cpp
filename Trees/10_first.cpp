#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node* build_tree(vector<int> &arr) {
    idx++;
    if(arr[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(arr[idx]);
    root->left = build_tree(arr);
    root->right = build_tree(arr);
    return root;


}
void preorder(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    
}
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void level_order(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }

}
void level__order(Node* root) {
    queue<Node* > q;
    q.push(root);
    q.push(NULL);
    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();
        if(curr == NULL) {
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }
        cout << curr->data << " ";
        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }
}
int count_nodes(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int left = count_nodes(root->left);
    int right = count_nodes(root->right);
    return (left + right + 1);
}
int height(Node* root) {
    if(root == NULL) {
        return 0;
    }
    int left = height(root->left) ;
    int right = height(root->right);
    return (max(left, right) + 1);
}
int diameter(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int left = diameter(root->left);
    int right = diameter(root->right);
    int curr = height(root->left) + height(root->right);
    return (max(curr,max(left, right)));

}

int main() {
    vector<int> arr= {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = build_tree(arr); 
    cout << diameter(root);
    cout << endl;

}