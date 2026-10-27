#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int solve(int n) {
    if(n == 0) {
        return 0;
    }
    int a = n;
    int maxi = INT_MIN;
    while(a > 0) {
        int rem = a%10;
        maxi = max(rem, maxi);
        a = a/10;
    }
    
    return 1 + solve(n-maxi);
}
int main() {
    int n;
    cin >> n;
    // int ans = solve(n);
    
    // cout << ans << endl;

    vector<int>dp(n+1, INT_MAX); 
    
    
    dp[0] = 0;
    
    for(int i =1; i<=n; i++  ) {
        int a = i;
        while(a > 0) {
            int rem = a %10;
            if(rem != 0) {
                dp[i] = min(dp[i], 1 + dp[i-rem]);
            }
            a = a/10;
        }

    }
    cout << dp[n] << endl;
}