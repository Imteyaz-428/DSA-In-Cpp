#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<pair<int,int>> *adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new vector<pair<int,int>> [V];
    }
    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int mincost( int src, vector<bool>&isMst) {
        int cost =0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({0,src});
        
        while(pq.size() > 0) {
            int wt = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if(!isMst[v]) {
                cost += wt;
                isMst[v] = true; 
                for(auto i : adj[v]) {
                    
                    pq.push({i.second, i.first});
                }
            }
        }
        return cost;
    }
    int prism() {
        int src =0;
        vector<bool>isMst(V,false);
        return mincost(src, isMst);
    }
};

int main() {
    Graph V(5);
    V.addEdge(0,1,10);
    V.addEdge(0,2,15);
    V.addEdge(0,3,30);
    V.addEdge(1,3,40);
    V.addEdge(2,3,50);
    cout << "min cost : " <<  V.prism() << endl;
    

}