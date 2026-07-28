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
        this->V= V;
        l = new list<int>[V];
    }

    // directed graph
    void addEdge(int p, int q) { 
        l[p].push_back(q);
    }
    
    // cycle detection
    bool cycleDetectionHelper(int src, vector<bool>& vis, vector<bool>&recPath) {
        vis[src] = true;
        recPath[src] = true; 
        for(int i : l[src]) {
            if(!vis[i]) {
                if(cycleDetectionHelper(i,vis, recPath)) {
                    return true;
                }
            } else if(recPath[i] == true) {
                return true;
            } 
        }
        recPath[src] = false;
        return false;
    }

    bool isCycle() {
        
        vector<bool> vis(V,false);
        vector<bool> rePath(V, false);
        for(int src =0; src<V; src++) {
            if(!vis[src]) {
                if(cycleDetectionHelper(src, vis, rePath)) {
                    return true;
                }
            }
        }
        return false;
    }
}; 

int main() {
    Graph V(4);
    V.addEdge(1,0);
    V.addEdge(0,2);
    V.addEdge(2,3);
    V.addEdge(3,0);
    cout << V.isCycle() << endl;
}