#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

vector<string> ans;
void dfss(vector<vector<char>> &arr, int i, int j, vector<vector<bool>>&vis, int &count,string curr) {
    if(i < 0 || j < 0 || i >= arr.size() || j >= arr[i].size() || arr[i][j] == '#' || vis[i][j]) {
        return ;
    }
    if(arr[i][j] == 'B') {
        ans.push_back(curr);
        return;
    }
    
    vis[i][j]= true;
    count = count+1;
    dfss(arr, i-1, j,vis,count, curr + 'U');
    dfss(arr, i, j-1,vis,count, curr+'L');
    dfss(arr , i+1, j,vis,count, curr + 'D');
    dfss(arr, i, j+1,vis,count,curr + 'R');

}

int main() {
    int n, m;
    cin >>n >> m;
    vector<vector<char>> maps(n,vector<char>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> maps[i][j];
        }
    }
    int count =0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(maps[i][j] == 'A' && !vis[i][j]) {
                dfss(maps, i, j, vis, count,"");
                count++;
            }
        }
    }
    if(ans.size() > 0) {
        int a = INT_MAX;
        string curr ;
        for(int i=0; i<ans.size(); i++ ) {
            if(ans[i].size() < a) {
                curr = ans[i];
                a = ans[i].size();
            }
        }
        cout << "YES" << endl;
        cout << curr.length() << endl;
        cout << curr << endl;
    } else {
        cout << "NO" << endl;
    }
    
    

    
}