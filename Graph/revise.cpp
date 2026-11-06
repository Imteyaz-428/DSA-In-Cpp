#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


class Graph {
public: 
    int V;
    list<int> *l;
    Graph(int V) {
        this->V =V;
        l = new list<int>[V];
    }
    void addEdge(int p, int q) {
        l[p].push_back(q);
        l[q].push_back(p);
    }
    void display() {
        for(int i=0; i<V; i++) {
            cout << i << "-> ";
            for(int j : l[i]) {
                cout << j << " ";
            }
            cout << endl;

        }

    }
    void dfs_helper(int source, vector<bool>&vis) {
        vis[source] = true;
        cout << source << " ";
        for(int i:l[source]) {
            if(!vis[i]) {
                dfs_helper(i, vis);
            }
        }
    }
    void dfs() {
        vector<bool>vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs_helper(i, vis);
            }
        }

        cout << endl;
    }

    void bfs() {
        int source =0;
        queue<int>q;
        vector<bool>vis(V, false);
        q.push(source);
        vis[source] = true;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            cout << front << " ";
            for(int i :l[front]) {
                if(!vis[i]) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        cout << endl;
    }

    bool cycle_detection_bfs() {
        queue<pair<int,int>>q;
        int source = 0;
        vector<bool>vis(V,false);
        vis[source] = true;
        
        q.push({source,-1});
        while(!q.empty()) {
            int el = q.front().first;
            int par = q.front().second;
            q.pop();
            for(int i : l[el]) {
                if(!vis[i]) {
                    q.push({i,el});
                    vis[i] = true;
                } else if(i != par) {
                    return true;
                }
            }
        }
        return false;


    }
    bool cycle_detection_dfs_helper(int curr, int par, vector<bool>&vis) {
        vis[curr] = true;
        for(int i : l[curr]) {
            if(!vis[i]) {
                if(cycle_detection_dfs_helper(i, curr, vis)) {
                    return true;
                }
            } else if(i != par) {
                return true;
            }
        }
        return false;
    }


    bool cycle_detection_dfs() {
        vector<bool>vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(cycle_detection_dfs_helper(i, -1, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    


};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(3,1);
    g.addEdge(3,2);
    g.addEdge(4,3);
    g.display();
    g.bfs();
    g.dfs();
    bool dfs_cycle = g.cycle_detection_dfs();
    bool cycle = g.cycle_detection_bfs();
    if(dfs_cycle) {
        cout << "cycle detected " << endl;
    } else {
        cout << "cycle not detected" << endl;
    }
}