#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>>search(int matrix[5][5], int rows, int colm , int key) {
    int i =0;
    int j = colm-1;
    vector<pair<int,int>>ans;
    while(i<rows && j>=0) {
        if(matrix[i][j] == key) {
            ans.push_back({i,j});
            return ans;
        } else if(matrix[i][j] < key) {
            i++;
        } else{
            j--;
        }


    }
    return {{-1,-1}};
}

int main() {
    int matrix[5][5] = {{1,4,7,11,5},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,23},{18,21,23,26,30}};
    int rows=5;
    int colm=5;
    int key =19;
    auto val = search(matrix, rows, colm, key);
    for(auto i: val) {
        cout << i.first << "," << i.second << endl;
    }
}
