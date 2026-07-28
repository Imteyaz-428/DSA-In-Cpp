#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    } 
    void addEdge(int p, int q) {
        l[p].push_back(q);
        l[q].push_back(p);
    }
    void display() {
        for(int i=0; i<V; i++) {
            cout << i << " -> ";
            for(int j: l[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    void BFS() {
        vector<bool> vis(V,false);
        queue<int>Q;
        Q.push(0);
        vis[0] = true;
        while(Q.size() > 0) {
            int curr = Q.front();
            cout << curr << " ";
            Q.pop();
            for(int i : l[curr]) {
                if(!vis[i]) {
                    Q.push(i);
                    vis[i] = true;
                }
            }
        }
        cout << endl;
    }
    void dfsHelper(int src, vector<bool>& vis) {
        vis[src] = true;
        cout << src << " ";
        for(int v : l[src]) {
            if(!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }
    void dfs() {
        vector<bool>vis(V, false);
        for(int i=0; i<V; i++) { 
            if(!vis[i]) {
                dfsHelper(i,vis);
            }
        }
        cout << endl;
    }
    
};

int main() {
    Graph V(5);
    V.addEdge(0,1);
    V.addEdge(1,3);
    V.addEdge(2,1);
    V.addEdge(4,3);
    V.addEdge(4,1);
    V.display();
    V.BFS();
    V.dfs();
}