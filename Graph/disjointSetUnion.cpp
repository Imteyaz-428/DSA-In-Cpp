#include <iostream>
#include <vector>
#include <list>
using namespace std;

class DisjointSetUnion {
public :
    int n;
    vector<int> par, rank;
    DisjointSetUnion(int n) {
        this->n = n;
        for(int i=0; i<n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    void Union(int a , int b) {
        int parA = find(a);
        int parB = find(b);
        if(parA == parB) {
            return ;
        }
        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        } else if(rank[parA] > rank[parB]) {
            par[parB] = parA;
        } else {
            par[parA] = parB;
        }
    }
    void getInfo() {
        for(int i=0; i<n; i++) {
            cout << par[i] << ' ';
        }
        cout << endl;
        for(int i=0; i<n; i++) {
            cout << rank[i] << ' ';
        }
        cout << endl;
    }

};

int main() {
    DisjointSetUnion dsu(6);
    dsu.Union(0,2);
    cout << dsu.find(2) << endl;
    dsu.Union(1,3);
    dsu.Union(2,5);
    dsu.Union(0,3);
    cout << dsu.find(2) << endl;
    dsu.Union(0,4);
    dsu.getInfo();
}