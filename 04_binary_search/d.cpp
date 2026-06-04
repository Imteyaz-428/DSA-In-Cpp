#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n =4;
    string str[4];
    for(int i =0; i<n; i++) {
        cin >> str[i] ;
    }
    for(int i=0; i<n; i++) {
        cout << str[i] << endl;
    }
}