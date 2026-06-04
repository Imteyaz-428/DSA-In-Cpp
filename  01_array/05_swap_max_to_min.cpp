#include <iostream>
using namespace std;

void swapMaxtoMin(int arr[5], int size) {
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int minIndex = 0;
    int maxIndex =0;
    for(int i= 0; i<size; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
            minIndex = i;
        } 
        if(arr[i] > largest) {
            largest = arr[i];
            maxIndex = i;
        }
    }
    swap(arr[minIndex], arr[maxIndex]);
    
    cout << "elements after the swapping : ";
    for(int i = 0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
int main() {
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    swapMaxtoMin(arr, size);

}