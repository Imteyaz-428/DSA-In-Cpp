#include <iostream>
#include <vector>
using namespace std;

long long  mod = 1e9 + 7;
long long solve(long long  n, long long  i,vector<long long >&dp) {
    if(i > n) {
        return 0;
    } 
    if(i == n) {
        return 1;
    }
    if(dp[i] != -1) {
        return dp[i]%mod;
    }
    long long  a = solve(n , i+1,dp);
    long long  b = solve(n , i+2,dp);
    long long  c = solve(n , i+3,dp);
    long long  d = solve(n , i+4,dp);
    long long  e = solve(n , i+5,dp);
    long long  f = solve(n , i+6,dp);
    return dp[i] = (a+b+c+d+e+f) %mod;
}
int  main() {

    long long  n ;
    cin >> n;
    vector<long long > dp(n+7, -1);
    // long long  ans = solve(n, 0,dp)%mod;
    // cout << ans << endl;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    for(int i= 7; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6])%mod;
    }
    cout << (dp[n]%mod)<<  endl;

    return 0;
}