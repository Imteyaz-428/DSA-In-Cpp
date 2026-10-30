#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++) {
        int prev = -1;
        for(int j=1; j<=n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            int b = INT_MIN;
            if(i >= j && (prev == -1 || arr[j-1] > arr[prev])) {
                b = max(dp[i][j], dp[i-1][j-1]+1);
                prev = j-1;
            }
            dp[i][j] = max(dp[i][j],b);
        }
    }
    // for(int i = n-1; i >=0; i--) {
    //     for(int j =n-1; j >=0; j--) {
    //         dp[i][j] = dp[i+1][j+1];
    //         if(arr[i] > arr[j]) {
    //             dp[i][j] =  max(dp[i][j],1 + dp[i+1][i+1]);
    //         }
    //     }
    // }
    cout << dp[n][n] << endl;

    for(int i=1; i<=n; i++) {
        int prev = -1;
        for(int j=0; j<=n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

}