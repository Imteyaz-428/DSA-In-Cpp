#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;


struct Node {
    int node;
    int cost;
    int stop;
};

class Graph {
public:
    int V;
    list<pair<int,int>> *l;
    Graph(int V) {
        this->V = V;
        l = new list<pair<int,int>> [V];
    }
    void addEdge(int p, int q, int wt ) {
        l[p].push_back({q,wt});
        
    }
    void display() {
        for(int i=0; i<V; i++) {
            cout << i << " -> ";
            for(auto j : l[i]) {
                cout << j.first << "with weight  " <<  j.second;
            }
            cout << endl;
        }
    }

    int  modified_dfs(int src, int dest, int k, vector<int> &dist) {
         
        queue< Node>q;
        dist[src] =0;
        q.push({src, 0, -1});
        while(q.size() > 0) {
            Node curr =  q.front();
            q.pop();
            if(curr.stop > k) {
                continue;
            }
            for(auto j : l[curr.node]) {
                int newcity = j.first;
                int price = j.second;
                int newcost = curr.cost + price;
                if(dist[newcity] > newcost) { 
                    dist[newcity] = newcost;
                    q.push({newcity,price, curr.stop+1});
                }


            }

        }
        if(dist[dest] == INT_MAX) {
            return -1;
        }
        return dist[dest];
        
    }


    
};

int main() {
    vector<vector<int>> flights = {{0,1,100}, {1,2,100}, {2,0,100},{1,3,600}, {2,3,200}};
    int n = 4;
    int src = 0;
    int dest = 3;
    int k = 1;
    Graph V(n);
    for(int i=0; i<n; i++) {
        V.addEdge(flights[i][0],flights[i][1], flights[i][2]);
    }
    V.display();
    vector<int> dist(n, INT_MAX);
    cout << V.modified_dfs(src, dest, k, dist) << endl;


}