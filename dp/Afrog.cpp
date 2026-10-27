#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int Afrog(vector<int>&arr, int i,vector<int>&dp) {
    if(i >= arr.size()-1) {
        return 0;
    }
    if(dp[i] != -1) {
        return dp[i];
    }
    int a = abs(arr[i+1] - arr[i]) +  Afrog(arr, i+1,dp);
    int b = INT_MIN;
    if(i < arr.size()-1) {
        b = abs(arr[i+2] - arr[i])+ Afrog(arr, i+2,dp);
    }
    return dp[i] = min(a,b);
}

int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int>dp(n+1, -1);
    cout << Afrog(arr, 0,dp) << endl;

    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    for(int i =2; i<n;i++) {
        int jump1 = abs(arr[i]- arr[i-1]) + dp[i-1];
        int jump2 = abs(arr[i] - arr[i-2]) + dp[i-2];
        dp[i] = min(jump1, jump2);
    }

}