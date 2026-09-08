#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
    int u;
    int wt;
    Edge(int u, int wt) {
        this->u = u;
        this->wt = wt;
    }
};

class Graph {
public:
    int V;
    vector<vector<Edge>> adj;
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v, int wt) {
        adj[u].push_back(Edge(v,wt));
        adj[v].push_back(Edge(v, wt));
    }

    void floyd() {
        int inf = 1e9;
        vector<vector<int>> dist(V, vector<int>(V,inf));
        for(int i=0; i<V; i++) {
            dist[i][i] = 0;
        }
        for(int i=0; i<V; i++) {
            for(auto e : adj[i]) {
                int u = e.u;
                int wt = e.wt;
                dist[i][u] = wt;
            }
        }

        for(int k=0; k<V; k++) {
            for(int i=0; i<V; i++) {
                for(int j=0; j<V; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for(int i=0; i<V; i++) { 
            for(int j=0; j<V; j++) {
                if(dist[i][j] == inf) {
                    cout << "inf ";
                } else {
                    cout  << dist[i][j] << " " ;
                }

            }
            cout << endl;
        }
    }


};

int main() {
    Graph g(4);
    g.addEdge(0,1,4);
    g.addEdge(0,2,11);
    g.addEdge(1,2,2);
    g.addEdge(1,3,8);
    g.addEdge(2,3,3);
    g.floyd();

}