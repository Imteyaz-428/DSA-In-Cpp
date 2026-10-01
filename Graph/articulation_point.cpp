#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <list>
using namespace std;

class Graph {
public: 
    int V;
    vector<vector<int>> adj;
    int time =0;
    vector<int>dt;
    vector<int>low;
    
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int p, int q) {
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    void dfs(int u, int parU, vector<bool>&vis,set<int>&s) {
        vis[u] = true;
        dt[u] = low[u] = ++ time;
        int child= 0;
        for(int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];
            if(!vis[v]) {
                child++;
                dfs(v, u, vis,s);
                low[u] = min(low[u], low[v]);
                if(parU != -1 && low[v] >= dt[u]) {
                    s.insert(u);
                }
                
            } else if(v != parU) {
                low[u] = min(low[u],low[v]);
            }
        }
        if(parU == -1 && child > 1) {
            s.insert(u);
        }
    }

    void articulation() {
        time =0;
        dt.resize(V);
        low.resize(V);
        vector<bool>vis(V,false);
        set<int>s;
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, -1, vis,s);
            }
        }
        for(auto it = s.begin(); it != s.end(); it++) {
            cout << *(it) << " " ;
        }
        cout << endl;


    }


};

int main() {
    Graph g(6);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(4,3);
    g.addEdge(4,1);
    g.articulation();
   
    
    

}