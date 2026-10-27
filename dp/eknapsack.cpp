#include <iostream>
#include <vector>
#include <climits>
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
    int sum =0;
    for(int i=0; i<n; i++) {
        sum += v[i];
    }

    
    vector<vector<long long >>temp(n+1, vector<long long>(sum+1,LLONG_MAX / 2));
   
    for(int i=0; i<=n; i++) {
        temp[i][0] = 0;
    }
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            // long long a = temp[i-1][j];
            // long long  b =0;
            // if(w[i-1] <= j ) {
            //     b = v[i-1] + temp[i-1][j-w[i-1]];
                
            // }
            // temp[i][j] = max(a, b);
            temp[i][j]  = temp[i-1][j];
            
            if( v[i-1]  <= j) {
                temp[i][j] = min(temp[i][j],temp[i-1][j-v[i-1]] + w[i-1] );
            }
            


        }
        
    }

    int ans = 0;

    for(int j = 0; j <= sum; j++) {
        if(temp[n][j] <= W) {
            ans = j;
        }
    }
    // for(int i=n; i<n+1; i++) {
    //     for(int j=0; j<sum+1; j++) {
    //         cout << temp[i][j] << " ";
    //     }
    // }
    
    cout << ans << endl;

}