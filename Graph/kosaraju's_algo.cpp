#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// time comp :- O(v+E) + O(V+ E) + O(V+ E) = O(V+ E)

class Graph {
public :
    int V;
    vector<vector<int>> adj;
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int p, int q) {
        adj[p].push_back(q);
    }
    void topoSort(int src, stack<int>&s, vector<bool>&vis) {
        vis[src] = true;
        for(int i : adj[src]) {
            if(!vis[i]) {
                topoSort(i, s, vis);
            }
        }
        s.push(src);
    }

    void dfs(int src, vector<bool>&vis, vector<vector<int>> &tranpose) {
        vis[src] = true;
        cout << src << " " ;
        for(int i : tranpose[src]) {
            if(!vis[i]) {
                dfs(i, vis, tranpose);
            }
        }

    }

    void kosaraju() {

        // topological sort
        stack<int>s;
        vector<bool>vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                topoSort(i, s, vis);
            }
        }

        //transpose the graph
        vector<vector<int>> transpose(V);
        for(int u=0; u<V; u++) {
            vis[u] = false;
            for(int j : adj[u]) {
                transpose[j].push_back(u);
            }
        }


        // dfs on transpose
        cout << "print SCC :"; 
        while(s.size() > 0) {
            int comp = s.top();
            s.pop();
            if(!vis[comp]) {
                dfs(comp, vis, transpose);
                cout << endl;
            }

        }



    }
};

int main() {
    Graph g(5);

    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,0);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.kosaraju();
    return 0;
}