#include <iostream>
using namespace std;
#include<unordered_map>;

class LRUCache {
    public:
    
        class Node {
        public:
            int key, val;
    
            Node*next ;
            Node*prev;
            Node(int k, int v) {
                key = k;
                val = v;
                next = prev = NULL;
    
            }
    
        };
        Node* head = new Node(-1, -1);
        Node* tail = new Node(-1,-1);
        unordered_map<int, Node*> m;
        int limit;
    
    
        LRUCache(int capacity) {
            limit = capacity;
            head->next = tail;
            tail->prev = head;
        }
        
        int get(int key) {
            if(m.find(key) == m.end()) {
                return -1;
            }
            
            Node* ansNode = m[key];
            int ans = ansNode->val;
            m.erase(key);
            delete_node(ansNode);
            addNode(ansNode);
            m[key] = ansNode;
            return ans;
            
        }
        void addNode(Node* newNode) {
            Node* oldNode = head->next;
            head->next = newNode;
            oldNode->prev = newNode;
            newNode-> next = oldNode;
            newNode->prev = head;
        }
        void delete_node(Node* oldnode) {
            Node* oldprev = oldnode->prev;
            Node* oldnext = oldnode->next;
            oldprev->next = oldnext;
            oldnext->prev = oldprev;
        }
        
        void put(int key, int val) {
            if(m.find(key) != m.end()) {
                Node* oldNode = m[key];
                delete_node(oldNode);
                m.erase(key);
            }
            
            if(m.size()== limit) {
                // delete the LRU cache
                m.erase(tail->prev->key);
                delete_node(tail->prev);
            }
    
            Node* newNode = new Node(key, val);
            addNode(newNode);
            m[key] = newNode;
            
        }
};

int main() {
    
    return 0;
}