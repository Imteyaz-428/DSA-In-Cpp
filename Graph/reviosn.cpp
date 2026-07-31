#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }
    void addEdges(int p, int q) {
        l[p].push_back(q);
        l[q].push_back(p);
    }
    void display() {
        for(int i=0; i<V;i++) {
            cout << i << " -> ";
            for(int j : l[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    void bfs() {
        queue<int> q;
        vector<bool> vis(V,false);
        q.push(0);
        vis[0] = true;
        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for(int i : l[curr]) {
                if(!vis[i]) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        cout << endl;
    }
    void dfsHelper(int source,queue<int>q, vector<bool>&vis) {
        vis[source] = true;
        cout << source << " ";
        for(int i:l[source]) {
            if(!vis[i]) {
                dfsHelper(i,q,vis);
            }
        }
    }
    void dfs() {
        queue<int> q;
        vector<bool>vis(V,false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfsHelper(i,q,vis);
            }
        }
    }
};

int main() {
    Graph V(5);
    V.addEdges(0,1);
    V.addEdges(2,1);
    V.addEdges(3,1);
    V.addEdges(4,0);
    V.addEdges(3,2);
    V.display();
    V.bfs();
    V.dfs();


}
