#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
public :    
    int V;
    list<int> *l;
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdje(int p, int q) {
        l[p].push_back(q);
    }
    void display() {
        for(int i =0; i<V; i++) {
            cout << i << " -> ";
            for(int j : l[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    void bfs() {
        queue<int>q;
        vector<bool>vis(V, false);
        q.push(0);
        vis[0] = true;
        while(!q.empty()) {
            int a = q.front();
            q.pop();
            cout << a << " ";
            for(int i : l[a]) {
                if(!vis[i]) {
                    q.push(i);
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
                dfsHelper(i, vis);
            }
        }
    }

    void dfs() {
        int src =0;
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfsHelper(i, vis);
            }
        }
        cout << endl;

    }

    void topo_sort() {
        vector<int>dist(V, INT_MAX);
        vector<int> indegree(V,0);
        for(int i=0; i<V; i++) {
            for(int j : l[i]) {
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0)  {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int a= q.front();
            q.pop();
            cout << a << " ";
            
            for(int i : l[a]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    bool cycle_detection_bfs() {
        int src =0;
        queue<pair<int,int>>q;
        vector<bool>vis(V, false);
        q.push({src, -1});
        vis[src] = true;
        while(!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            for(int i : l[a]) {
                if(!vis[i]) {
                    q.push({i, a});
                    vis[i] = true;
                } else if(a != b) {
                    return false;
                }

            }

        }
        return true;

    }



};