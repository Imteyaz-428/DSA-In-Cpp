#include <iostream>
using namespace std;

void reverseArray(int arr[6], int size, int st, int end) {
    while(st <= end) {
        swap(arr[st], arr[end]);
        st++;
        end--;
    }
    cout << "array after the reverse :" ;
    for(int i =0; i<size; i++) {
        cout << arr[i]  << " ";
    }
    cout << endl;

}
int main() {
    int arr[6] = {3,5,43,23,4,34};
    int size = sizeof(arr)/ sizeof(int);
    int st = 0; 
    int end = size-1;
    reverseArray(arr, size, st, end);
    return 0;
}