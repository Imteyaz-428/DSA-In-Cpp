#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    int W;
    cin >> n;
    cin >> W;
    vector<int>w(n);
    vector<int>v(n);
    for(int i=0; i<n; i++) {
        cin >> w[i];
        cin >> v[i];
    }
    
    vector<vector<long long>>temp(n+1, vector<long long>(W+1,0));
   
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            long long a = temp[i-1][j];
            long long  b =0;
            if(w[i-1] <= j ) {
                b = v[i-1] + temp[i-1][j-w[i-1]];
                
            }
            temp[i][j] = max(a, b);
        }
    }
    
    cout << temp[n][W] << endl;

}