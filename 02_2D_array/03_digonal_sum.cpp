#include <iostream>
#include <vector>
using namespace std;
int diagonal_sum(int matrix[3][3], int rows , int colm) {
    int sum=0;
    for(int i=0; i<rows; i++) {
        for(int j =0; j<colm; j++) {
            if(i==j) {
                sum+=matrix[i][j];

            } else if(j== 3-i-1) {

                sum+=matrix[i][j];
            }
        }
    }
    return sum;
}


int diagonalSum(int matrix[3][3], int rows , int colm) {
    int sum =0;
    for(int i=0; i<rows; i++) {
        sum += matrix[i][i];
        if(i != rows-i-1) {
            sum+=matrix[i][rows-i-1];
        }
    }
    return sum;
}
int main() {
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int rows= 3;
    int colm=3;
    cout << diagonalSum(matrix, rows, colm) << endl;

}