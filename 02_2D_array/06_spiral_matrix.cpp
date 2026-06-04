#include <iostream>
#include <vector>
using namespace std;
void arr(int matrix[4][4], int rows, int colm) {
    int strow=0, endrow= rows-1;
    int stcolm=0, endcolm= colm-1;
    vector<int> ans;
    while(strow<= endrow && stcolm <= endcolm) {
       //top
       for(int i=stcolm; i<=endcolm; i++) {
         ans.push_back(matrix[strow][i]);
       }

       //right
       for(int i =strow+1; i<=endrow; i++) {
        ans.push_back(matrix[i][endcolm]);
       }

       //bottom
       for(int i=endcolm-1; i>=strow; i--) {
        if(strow==endrow) {
            break;
        }
        ans.push_back(matrix[endrow][i]);
       }
       //left
       for(int i=endrow-1; i>=strow+1; i--) {
        if(stcolm== endcolm) {
            break;
        }
        ans.push_back(matrix[i][stcolm]);
       }
       strow++;
       endrow--;
       stcolm++;
       endcolm--;
    }
    for(int i =0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
    
}

int main() {
    int matrix[4][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int rows = 4;
    int colm =4;
    arr(matrix, rows, colm);

}