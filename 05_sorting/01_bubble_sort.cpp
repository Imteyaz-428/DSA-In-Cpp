#include <iostream>
#include <vector>
using namespace std;
void bubble_sort(int n , int arr[]) {
    for(int i=0; i<n-1; i++) {
        bool isswap = false;
        for(int j =0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isswap = true;
            }
        }
        if(!isswap) {
            return;
        }
    }
}
void print_array(int arr[], int n) {
    for(int i =0; i< n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 5;
    int arr[5] = {4,1,3,5,2};
    bubble_sort(n, arr) ;
    print_array(arr, n);
    return 0;

}