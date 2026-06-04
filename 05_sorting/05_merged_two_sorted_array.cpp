#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 3;
    int m = 3;
    int A[] = {1,2,3,0,0,0};
    int B[] = {2,5,6};
    int l = 5;
    int index =m+n-1;
    while(m >0 && n>0) { 
        if(A[m-1] <B[n-1]){
            A[index] = B[n-1];
            n--;
           
        } else{
            A[index] =A[m-1];
            m--;
           
        }
        index--;
    }
    while(n >=0) {
        A[index] = B[n-1];
    }
    for(int i =0 ; i<6; i++) {
        cout << A[i] <<  " ";
    }
    cout << endl;
}