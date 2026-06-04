#include <iostream>
using namespace std;

//fuction for printing the index of smallest and largest element
void index(int arr[9], int size , int smallest, int largest) {
    for(int i =0 ; i<size; i++) {
        if(arr[i] == smallest) {
            cout << "index of smallest element :" << i << endl;
        }
        if(arr[i] == largest) {
            cout << "index of largest element :" << i << endl;
        }
    }
}

//function for printing the element of smallest and largest element
void largest_smallest(int arr[9], int size) {
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for(int i = 0; i<size; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    cout << "smallest :" << smallest << endl;
    cout <<  "largest :" << largest << endl;

    index(arr, size, smallest, largest);
    
}
int main() {
    int arr[9] = {4,23,534,3,12,6,765,43,23};
    int size = sizeof(arr)/sizeof(int);
    largest_smallest(arr, size);
    return 0;
}