#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    void addEdges(int p, int q) {
        l[p].push_back(q);
       
    }
    void display() {
        for(int i=0; i<V;i++) {
            cout << i << " -> ";
            for(int j : l[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    void bfs() {
        queue<int> q;
        vector<bool> vis(V,false);
        q.push(0);
        vis[0] = true;
        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for(int i : l[curr]) {
                if(!vis[i]) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        cout << endl;
    }
    void dfsHelper(int source,queue<int>q, vector<bool>&vis) {
        vis[source] = true;
        cout << source << " ";
        for(int i:l[source]) {
            if(!vis[i]) {
                dfsHelper(i,q,vis);
            }
        }
    }
    void dfs() {
        queue<int> q;
        vector<bool>vis(V,false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfsHelper(i,q,vis);
            }
        }
    }

    bool cycle_detection() {
        int source = 0;
        queue<pair<int,int>> q;
        vector<bool>vis(V,false);
        q.push({source,-1});
        vis[source] = true;
        while(q.size() > 0) {
            auto a = q.front();
            q.pop();
            int curr = a.first;
            int par = a.second;
            for(int i:l[curr]) {
                if(!vis[i]) {
                    q.push({i, curr});

                } else if(i != par) {
                    return true;
                }
            }

        }
        return false;
    }
    bool helper(int source, vector<bool> & vis, int par) {
        vis[source] = true;
        for(int i: l[source]) {
            if(!vis[i]) {
                if(helper(i,vis,source)) {
                    return true;
                }
            } else if(i != par) {
                return true;
            }
        }
        return false;
    }
    bool cycle_detection_dfs() {
        int source = 0;
        vector<bool>vis(V,false);
        return helper(source, vis, -1);

    }
    void topological_sort() {
        int src = 0;
        queue<int> q;
    
        vector<int>indegree(V,0);
        for(int i=0; i<V; i++) {
            for(int j:l[i]) {
                indegree[j]++;
            }
        }
        for(int i=0; i<V;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(q.size() > 0) {

            int curr = q.front();
            cout << curr <<  " ";
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
    Graph V(5);
    V.addEdges(0,1);
    V.addEdges(2,1);
    V.addEdges(3,1);
    V.addEdges(4,0);
    V.addEdges(3,2);
    V.display();
    V.bfs();
    V.dfs(); 
    cout << endl;
    cout <<  V.cycle_detection() << endl;
    cout << V.cycle_detection_dfs() << endl;
    V.topological_sort();



}
