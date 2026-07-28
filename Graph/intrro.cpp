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
    void addAjency(int p, int  q) {
        l[p].push_back(q) ;
        l[q].push_back(p);

    }
    void display() {
        for(int i=0; i<V; i++) {
            cout << i << " :";
            for(int i: l[i]) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    void BFS() {
        queue<int> Q;
        vector<bool> vis(V,false);
        Q.push(0); 
        vis[0] = true;
        while(Q.size() > 0)  {
            int u = Q.front();
            Q.pop();
            cout << u << " ";
            for(int i: l[u]) {
                if(!vis[i]) {
                    Q.push(i);
                    vis[i] = true;
                }
            }
            
        }
        cout << endl;
    }
    void DFSHelper(int u, vector<bool> &vis)  {
        cout << u << " ";
        vis[u] = true;
        for(int i: l[u]) {
            if(!vis[i]) {
               
                DFSHelper(i, vis);
            }
        }
        
    }
    void DFS() {
        int src =0;
        vector<bool> vis(V,false);
        DFSHelper(src, vis);
    }
    bool cycleDetectionHelper(int src, vector<bool>&vis, int par) {
        vis[src] = true;
        for(int i: l[src]) {
            if(!vis[i]) {
                if(cycleDetectionHelper(i,vis, src)) {
                    return true;
                }
            } else if(i != par) {
                return true;
            }
        }
        return false;
    }


    bool isCycle() {
        int src =0;
        vector<bool> vis(V,false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(cycleDetectionHelper(i,vis, -1)) {
                    return true;
                }
            }
        }
        return false;
    
    }
};




int main() {
    Graph V(4);
    V.addAjency(0,1);
   
    V.addAjency(1,2);
    V.addAjency(1,3);
    
    V.addAjency(2,3);
    
   
    
    // V.display();
    // V.BFS();
    
    V.DFS();
    cout << endl;

    cout << V.isCycle() << endl;
}