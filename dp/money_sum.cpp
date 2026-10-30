#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int sum =0;
    for(int i=0; i<n;i++) {
        sum += arr[i];
    }

    vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            if(j == arr[i-1]) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            int b = 0;
            if(j > arr[i-1]) {
                if(dp[i-1][j-arr[i-1]]) {
                    b =1;
                }
            }
            dp[i][j] = max(dp[i][j], b);
        }
    }
    int count =0;
    vector<int>temp;
    for(int i=0; i<= sum+1; i++) {
        if(dp[n][i] == 1) {
            temp.push_back(i);
            count++;
        }
    }
    cout << count << endl;
    for(int i : temp) {
        cout << i << " ";
    }
    cout << endl;
}