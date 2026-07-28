#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list <int> *l; // int *arr
public :
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];  // arr = new int[V]
    }
    void addAdjencey(int p, int q) {
        l[p].push_back(q);
        l[q].push_back(p);
    }

    void display() {
        for(int i=0; i<V; i++) {
            cout << i << " :";
            for(int j : l[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    void BFS() {
        queue<int> Q;
        Q.push(0);
        vector<bool >vis(V,false);
        vis[0] = true;
        while(Q.size() > 0) {
            int u = Q.front();
            Q.pop();
            cout << u << " ";
            for(int i : l[u]) {
                if(!vis[i]) {
                    Q.push(i);
                    vis[i] = true;
                }
            }
        }
        cout << endl;
    }
    void dfsHelper(int src, vector<bool>&vis) {
        
        cout << src << " ";
        vis[src] = true;
        for(int i : l[src]) {
            if(!vis[i]) {
                dfsHelper(i,vis);
            }
        }
    }
    void  dfs() {
        int src=0;
        vector<bool>vis(V,false);
        dfsHelper(src, vis);
    }

    bool isCycleUsingBFS() {
        int src =0;
        vector<bool> vis(V,false);
        queue<pair<int,int>> Q;
        Q.push({src, -1});
        vis[src] = true;
        while(Q.size() > 0) {
            int v = Q.front().first; 
            Q.pop();
            for(int i : l[v]) {
                if(!vis[i]) {
                    vis[i] = true;
                    Q.push({i,v});
                } else if(i != Q.front().second) {
                    return true;
                }
            }
        }
        return false;
    }


};
int main() {
    Graph V(4);
    V.addAdjencey(0,1);
    V.addAdjencey(1,2);
    V.addAdjencey(1,3);
    V.addAdjencey(2,3);
    // V.display();
    V.BFS();
    V.dfs();
    cout << endl;
    cout << V.isCycleUsingBFS() << endl;
}