#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int>arr(n);
    vector<int>vec(m);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int j=0; j<m; j++) {
        cin >> vec[j];
    }
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int a = max(dp[i-1][j], dp[i][j-1]);
            int b = INT_MIN;
            if(arr[i-1] == vec[j-1]) {
                b= dp[i-1][j-1] +1;
            }
            dp[i][j] = max(a,b);
        }

    }
   
    vector<int> curr;
    int prev = 0;
    int i=n; 
    int j=m;
    while(i >=1 && j >= 1) {
        // if(dp[i][j-1]  > dp[i-1][j]) {
        //     j = j-1;
        //     if(arr[i-1] == vec[j-1]) {
        //         curr.push_back(arr[i-1]);
                
        //     }
           
        // } else if(dp[i][j-1] < dp[i-1][j]) {
        //     if(arr[i-1] == vec[j-1]) {
        //         curr.push_back(arr[i-1]);
                
        //     }
        //     i = i-1;
        // } else {
        //     if(arr[i-1] == arr[j-1]) {
        //         curr.push_back(arr[i-1]);
        //     }
        //     j = j-1;
        //     i = i-1;
        // }

        if(arr[i-1] == vec[j-1] && dp[i][j] == dp[i-1][j-1]+1) {
            curr.push_back(arr[i-1]);
            i--;
            j--;
        }  else {
            if(dp[i][j-1]  > dp[i-1][j]) { 
                j = j-1;
            } else if(dp[i][j-1] < dp[i-1][j]) {
                i =i-1;
            } else {
                i--;
                
            }
        }

    }
    reverse(curr.begin(), curr.end());
    cout << dp[n][m] << endl;
    // cout << curr.size();
    for(int i=0; i<curr.size(); i++) {
        cout << curr[i] << " ";
    }

    cout << endl;
    

}
