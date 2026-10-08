#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Edge {
public:
    int v;
    int wt;
    Edge( int v, int wt) {
        
        this->v = v;
        this->wt=wt;
    }
};
class Graph {
    int V;
    vector<vector<int>>adj;
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        
    } 
    void addEdge(int p, int q) {
        adj[p].push_back(q);
    }
    void print() {
        for(int i=0; i<V; i++) {
            cout << i << " -> ";
            for(int a : adj[i]) {
                cout << a << " ";
            }
            cout << endl;
        }
    }

};

int main() {
    Graph g(6);
    int V =6;
    vector<vector<Edge>>adj(V);
    adj[1].push_back(Edge(2,3));
    adj[4].push_back(Edge(2,5));
    adj[1].push_back(Edge(3,5));
    adj[2].push_back(Edge(5,3));
    adj[1].push_back(Edge(4,8));
    for(int i=0; i<V; i++) {
        cout << i << " -> ";
        for(int j =0; j< adj[i].size();j++) {
            Edge  a = adj[i][j];
            cout << a.v << " ";
            cout << "wt " << a.wt << " ";
        }
        cout << endl;
    }
    // g.print();
    


}