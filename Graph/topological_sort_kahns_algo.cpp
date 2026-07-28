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
        l = new list<int> [V];
    } 
    void addEdge(int p, int   q  ) {
        l[p].push_back(q);
    }

    void display() {
        for(int i=0; i<V; i++) {
            cout << i << " :";
            for(int j:l[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void bfs() {
        queue<int>q;
        vector<bool>vis(V,false);
        q.push(0);
        vis[0] = true;
        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for(int i: l[curr]) {
                if(!vis[i]) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }

    void dfsHelper(int src, vector<bool>&vis) {
        cout << src << " ";
        vis[src]= true;
        for(int i: l[src]) {
            if(!vis[i]) {
                dfsHelper(i,vis);
            }
        }
    }
    void dfs() {
        vector<bool> vis(V, false);
       
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfsHelper(i, vis);
            }
        }
    }
    void topological_sort() {
        queue<int> q;
        vector<int> indegree(V,0);
        for(int u=0; u<V; u++) {
            for(int v : l[u]) {
                indegree[v]++;
            }
        }
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(q.size()> 0) {
            int curr = q.front();
            cout << curr << " ";
            q.pop();
            for(int i:l[curr]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
    }

};

int main() {
    Graph V(6);
    V.addEdge(4,0);
    V.addEdge(5,0);
    V.addEdge(5,2);
    V.addEdge(2,3);
    V.addEdge(3,1);
    V.addEdge(4,1);
    V.display();
    V.dfs();
    cout << endl;
    V.topological_sort();
    cout << endl;
    
}


