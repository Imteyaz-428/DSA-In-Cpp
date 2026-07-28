#include <iostream>
#include <vector>
#include <queue>
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
    void addEdge(int p, int q) {
        l[p].push_back(q);
        l[q].push_back(p);

    }
    bool dfs(int src, vector<bool>&vis, int par) {
        vis[src] = true;
        for(int v: l[src]) {
            if(!vis[v]) {
                if(dfs(v,vis,src)) {
                    return true;
                }
            } else if(v != par) {
                return true;
            }
        }
        return false;
    }

    bool isCycle() {
        int src =0;
        vector<bool>vis(V,false);
        return dfs(src,vis, -1);
    }
};

int main() {
    Graph V(5);
    V.addEdge(0,1);
    V.addEdge(0,2);
    V.addEdge(0,3);
    V.addEdge(1,2);
    V.addEdge(3,4);
    cout << V.isCycle() << endl;

    return 0;
}