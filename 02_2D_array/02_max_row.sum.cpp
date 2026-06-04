#include <iostream>
#include <vector>
using namespace std;

int main() {
    int matrix[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
    int rows=3;
    int colm=3;
    int maxsum= INT_MIN;

    for(int i=0;i<rows;i++) {
        int sum =0;
        for(int j=0;j<colm;j++) {
            sum = sum+matrix[i][j];
            maxsum = max(maxsum,sum);
        }
        
    }
    cout << maxsum << endl;
    
}