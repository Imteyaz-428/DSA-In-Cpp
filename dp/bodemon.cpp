#include <iostream>
using namespace std;
#include <vector>

int helper(vector<int>&arr, int n, vector<int> &dp) {
    if(n >= arr.size()) {
        return 0;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    int one = arr[n]*n + helper(arr, n+2,dp);
    int two =  0 + helper(arr, n+1,dp);
    return dp[n] = max(one, two);
}

int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin>> arr[i];
    }
    int maxi = arr[0];
    for(int i=0; i<n; i++) {
        maxi = max(arr[i], maxi);
    }
    vector<int>nums(maxi+1, 0);
    for(int i=0; i<n; i++) {
        nums[arr[i]]++;
    }
    vector<int>dp(maxi+1, -1);
    int ans = helper(nums, 0, dp);
    for(int i=0; i<maxi+1; i++) {
        cout << dp[i] << " " << endl;
    }
    cout << ans;
    

}