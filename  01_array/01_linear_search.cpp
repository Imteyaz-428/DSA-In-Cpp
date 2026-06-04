#include <iostream>
using namespace std;

void linearSearch(int arr[9], int size, int target) {
    for(int i=0; i<size; i++) {
        if(arr[i] == target) {
            cout << "target is found" << endl;
            cout <<"index :" <<  i << endl;
            break;
        }
    }
}
int main() {
    int arr[6] = {53,64,32,6,43,98};
    int size = sizeof(arr)/sizeof(int);
    int target = 98;
    linearSearch(arr, size, target);
    return 0;
}