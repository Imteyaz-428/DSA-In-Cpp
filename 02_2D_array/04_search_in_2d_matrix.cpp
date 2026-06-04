#include <iostream>
#include <vector>
using namespace std;

int isvalidcolm(int matrix[3][4], int rows, int colm, int key,int row) {
    int st =0; 
    int end =3;
    while(st<= end) {
        int mid= (st+end)/2;
        if(matrix[row][mid]==key) {
            return mid;
        } else if(matrix[row][mid] >key) {
            end=mid-1;
        } else{
            st =mid+1;
        }
    }
    return -1;
}

vector<pair<int,int>>search(int matrix[3][4], int rows, int colm, int key) {
    vector<pair<int,int>>ans;
    int st =0;
    int end =2;
    while(st <= end) {
      int mid = (st+end)/2;
      if(matrix[mid][0] <= key && matrix[mid][colm-1] >= key) {
         int j=isvalidcolm(matrix, rows, colm, key,mid) ;
        ans.push_back({mid,j});
        return ans;


      } else if(key > matrix[mid][colm-1]) {
        st= mid+1;
      } else{
         end = mid-1;
      }
    }
    return {{-1,-1}};
}

int main() {
    int matrix[3][4]= {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int rows =3;
    int colm=4;
    int key=34;
    auto val= search(matrix, rows, colm, key);
    for(auto i : val) {
        cout << i.first << "," << i.second << endl;
    }
}