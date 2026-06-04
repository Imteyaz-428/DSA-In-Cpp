#include <iostream>
#include <vector>
using namespace std;

bool isvalid(int n, vector<string> board, vector<vector<string>>ans, int row, int p) {
    //horizontal
    for(int i =0; i<n; i++ ) {
        if(board[row][i] == 'Q') {
            return false;
        }
    }
    //vertical
    for(int i =0; i<n; i++) {
        if(board[i][p] == 'Q') {
            return false;
        }
    }
    //left diagonal
    for(int i=row, j=p; i>=0 && j>=0; j--, i--) {
        if(board[i][j]== 'Q') {
            return false;
        }
    }
    // right diagonal
    for(int i =row, j =p; i>=0 && j<n; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

void print_queen(int n, vector<string> &board,vector<vector<string>> &ans,int row) {
    if(row == n) {
        ans.push_back({board}); 
        return; 
    }
    for(int i =0; i<n; i++) {
        if(isvalid(n, board, ans, row,i)) {
            board[row][i]  = 'Q';
            print_queen(n, board, ans, row+1);
            //backtracking
            board[row][i] = '.';
        }
    }
}
int main() {
    int n =4;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    print_queen(n, board, ans, 0);
    for(auto i : ans) {
        for(auto j:i ) {
            cout << j << " ";
        }
        cout << endl;
    }
}