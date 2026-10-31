#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;


int main() {
    long long n;
    cin >> n;
    vector<long long>arr(n);
    for(long long i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    vector<vector<long long>>dp(n+1, vector<long long>(n+1, 0));
    // for(long long i=1; i<=n; i++) {
    //     long long prev = -1;
    //     for(long long j=1; j<=n; j++) {
    //         dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //         long long b = long long_MIN;
    //         if(i >= j && (prev == -1 || arr[j-1] > arr[prev])) {
    //             b = max(dp[i][j], dp[i-1][j-1]+1);
    //             prev = j-1;
    //         }
    //         dp[i][j] = max(dp[i][j],b);
    //     }
    // }
    for(long long i = n-1; i >=0; i--) {
        for(long long j =i-1; j >= -1; j--) {
            dp[i][j+1] = dp[i+1][j+1];
            long long a =0;
            if(j == -1 || arr[i] > arr[j]) {
                a = dp[i+1][i+1] +1;
            }
            dp[i][j+1] = max(dp[i][j+1],a);
        }
    }
    cout << dp[0][0] << endl;

    // for(long long i=1; i<=n; i++) {
    //     long long prev = -1;
    //     for(long long j=0; j<=n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

}