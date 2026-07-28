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
    void addEdge(int p, int q) {
        l[p].push_back(q);

    }
    void topological(int src, vector<bool>& vis, stack<int>&s) {
        vis[src] = true;
        for(int i: l[src]) {
            if(!vis[i]) {
                topological(i, vis, s);
            }
        }
        s.push(src);
    }
    void sorting() {
        int src = 0;
        vector<bool> vis(V,false);
        stack<int> s;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                topological(i,vis, s);
            }
        }
        while(s.size() > 0) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};




int main() {
    
    Graph V(6);
    V.addEdge(0,1);
    V.addEdge(1,2);
    V.addEdge(3,2);
    V.addEdge(5,2);
    V.addEdge(4,1);
    V.sorting();
    


   
}