#include <iostream>
#include <vector>
using namespace std;


// time comp:- O(2^n)
// space comp :- O(n)
int fibnacci(int n) {
    if(n == 1 || n == 0) {
        return n;
    } 
    return fibnacci(n-1) + fibnacci(n-2);

}

int main() {
    int n =5;

    cout << fibnacci(n) << endl;

}