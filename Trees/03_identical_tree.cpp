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
static int idx =-1;
Node* builtTree(vector<int> arr) {
    idx++;
    if(arr[idx] == -1 ) {
        return NULL;
    }
    Node* root = new Node(arr[idx]);
    root->left = builtTree(arr);
    root->right = builtTree(arr);
    return root;
}

Node* builttree(vector<int> num) {
    idx++;
    if(num[idx] == -1 ) {
        return NULL;
    }
    Node* root = new Node(num[idx]);
    root->left = builttree(num);
    root->right = builttree(num);
    return root;
}
bool isidentical(Node* first, Node* second) {
    if( first == NULL || second == NULL) {
        return first == second;
    }
    bool isleftsame = isidentical(first->left, second->left) ;
    bool isrightsame= isidentical(first->right, second->right);

    return isleftsame && isrightsame && first->data == second->data;



}
bool issubtree(Node* first, Node* second) {
    if(first == NULL || second == NULL) {
        return first == second;
    }
    if(first->data == second->data && isidentical(first, second)) {
        return true;
    }
    return issubtree(first->left, second->left) || issubtree(first->right , second->right);

}

int main() {
    vector<int> arr = {1,2,-1,-1,3,-1,-1};
    vector<int> num = {1,2,-1,-1,3,-1,-1};
    Node* first = builtTree(arr);
    idx= -1;
    Node* second = builttree(num);
    cout << isidentical(first, second) << endl;
    cout << issubtree(first, second) << endl;
    return 0;

}