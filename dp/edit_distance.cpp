#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;



int minDistance(string word1, string word2) {
    vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1, 9999));
    // return helper(word1, word2, 0,0,dp);
    int n = word1.size();
    int m = word2.size();
    for(int i=0; i<=n; i++) {
        dp[i][0] = i;
    }
    for(int i=0; i<=m; i++) {
        dp[0][i] = i;
    }
    for(int i=1; i<=word1.size(); i++) {
        for(int j =1; j<=word2.size(); j++) {
            
            int b = INT_MAX;
            if(word1[i-1] != word2[j-1]) {
                int c = 1 + dp[i-1][j];
                int d = 1 + dp[i][j-1];
                int e = 1 + dp[i-1][j-1];
                dp[i][j] = min(c, min(d,e));
            } else {
                dp[i][j] = dp[i-1][j-1];
            }
        }
        
    }
    
    return dp[word1.size()][word2.size()];

    
}
int main() {
    string s;
    string s1;
    getline(cin, s);
    getline(cin, s1);
   
    cout << minDistance(s, s1) << endl;
}

