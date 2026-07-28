#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int> *l; // int *arr
public :
    Graph(int V) {
        this->V= V;
        l = new list<int> [V]; // arr = new int[V]
    }
    void addAdjecency(int p, int q) {
        l[p].push_back(q);
        l[q].push_back(p);
    }
    void display() {
        for(int j=0; j<V; j++) {
            cout << j  <<  " :" ;
            for(int i : l[j]) {
                cout << i  << " ";
            }
            cout << endl;
        }
    }
    void BFS() { // Time comp :- O(V + E)
        queue<int >Q;
        vector<bool> vis(V,false);
        Q.push(0);
        vis[0] = true;
        while(Q.size()> 0 ) {
            int u = Q.front();
            Q.pop();
            cout << u  << " ";
            for(int negh: l[u]) { 
                if(!vis[negh]) {
                    Q.push(negh);
                    vis[negh] = true;
                }
            }
        }
        cout << endl;
    }
    void DFSHelper(int v, vector<bool>& vis) {
        cout << v << " ";
        vis[v] = true;
        for(int i: l[v]) {
            if(!vis[i]) {
                DFSHelper(i,vis);
            }
        }
    }
    void DFS() { // time comp :- O(V + E)
        int src = 0;
        vector<bool>vis(V,false);
        DFSHelper(src, vis);
    }
    bool cycleDetectionHelper(int src, vector<bool>&vis, int par) {
        vis[src] = true;
        for(int i: l[src]) {
            if(!vis[i]) {
                if(cycleDetectionHelper(i, vis,src)) {
                    return true;
                }
            } else if(i != par) {
                return true;
            }
        }
        return false;
    }
    bool isCycle() {
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(cycleDetectionHelper(i,vis,-1)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph V(4);
    V.addAdjecency(0,1);
    V.addAdjecency(1,2);
    V.addAdjecency(1,3);
    V.addAdjecency(2,3);
    V.BFS();
    // V.display();
    V.DFS();
    cout << endl;
    cout << V.isCycle() << endl;
}