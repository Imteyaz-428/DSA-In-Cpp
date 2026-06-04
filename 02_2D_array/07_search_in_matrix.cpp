#include <iostream>
#include <vector>
using namespace std;

int searchColm(vector<vector<int>> matrix, int i, int m, int target) {
    int st =0;
    int end = m-1;
    while(st <= end) {
        int mid = st + (end -st)/2;
        if(matrix[i][mid] == target) {
            return mid;
        } else if(matrix[i][mid] > target) {
            end = mid-1;
        } else {
            st = mid+1;
        }

    }
    return -1;
}

vector<int> search(vector<vector<int>> matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int st =0;
    int end = n-1;
    vector<int> ans;
    while(st <= end) {
        int mid = st+ (end-st)/2;
        if(matrix[mid][0] <= target && matrix[mid][m-1] >= target) {
            
            int colIdx = searchColm(matrix, mid, m, target);
            ans.push_back(mid);
            ans.push_back(colIdx);
            return ans;

        } else if(matrix[mid][0] > target) {
            end = mid-1;
        } else {
            st = mid+1;
        }
    }
    return {-1, -1};
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20}, {23,30,34, 60}};
    int target = 30;
    vector<int> ans = search(matrix, target);
    cout << "row :" << ans[0] << " colm :" << ans[1] << endl;

    
}