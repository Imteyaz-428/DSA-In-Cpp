#include <iostream>
#include <vector>
using namespace std;
//time comp = O(4^n^2)

void helper(vector<vector<int>> &mat, int row, int colm, string path , vector<string> &ans) {
    int n = mat.size();
    if(row<0 || colm < 0 || row >=n || colm >= n || mat[row][colm] == 0 || mat[row][colm] == -1) {
        return ;
    }
    if(row == n-1 && colm == n-1) {
        ans.push_back(path);
        return;
    }
    mat[row][colm] = -1; // visited
    helper(mat, row+1, colm, path+"D", ans); // down
    helper(mat, row-1, colm, path+"U", ans); // up
    helper(mat, row, colm-1, path+"L", ans); // left
    helper(mat, row, colm+1, path+"R", ans);// right

    //backtracking
    mat[row][colm] = 1; //unvisited
}

vector<string> findPath(vector<vector<int>>& mat) {
    vector<string> ans;
    string path = "";
    helper(mat, 0,0, path , ans);
    return ans;
}

int main() {
    vector<vector<int>> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans = findPath(mat);
    for(string path: ans) {
        cout << path << endl;
    }
    return 0;
}