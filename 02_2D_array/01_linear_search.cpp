#include <iostream>
#include <vector>
using namespace std;

vector<pair<int ,int>> linear_search(int matrix[][3], int rows , int colm , int key) {
    vector<pair<int,int>>ans;
    for(int i =0; i<rows; i++) {
        for(int j=0; j<colm; j++) {
            if(matrix[i][j]==key) {
                ans.push_back({i,j});
                return ans;
            }
        }
    }
    return {{-1,-1}};

}

int main() {
    int matrix[3][3]= {{0,1,2},{3,4,5},{6,7,8}};
    int rows=3;
    int colm = 3;
    int key =9;
    auto val=linear_search(matrix, rows, colm, key);
    for(auto i:val) {
        cout << i.first << ","  << i.second << endl;
    }
}