#include <iostream>
using namespace std;

void sumAndProduct(int arr[5],int size) {
    int sum =0;
    int product = 1;
    for(int i =0; i<size; i++) {
        sum = sum + arr[i];
        product = product * arr[i];
    }
    cout << "sum :" << sum << endl;
    cout << "product :" << product << endl;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    sumAndProduct(arr,size);
    return 0;
}