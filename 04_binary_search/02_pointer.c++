#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a = 5;
    cout << a << endl;
    int* ptr = &a;
    int** ptr2 = &ptr;
    cout << *ptr << endl;
    cout << **ptr2 << endl;
    
}