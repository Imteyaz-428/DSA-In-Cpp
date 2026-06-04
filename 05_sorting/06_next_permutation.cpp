#include <iostream>
#include <vector>
using namespace std;
void next_permutation(int arr[], int n) {
    int pivot = -1;
    for(int i=n-2; i>=0; i--) {
        if(arr[i] < arr[i+1]) {
            pivot =i;
            break;

        }
    }
    // find righmost element
    
    for(int i = n-1; i>pivot; i--)  {
        if(arr[i] > arr[pivot]) {
           
            swap(arr[i], arr[pivot]);
            break;
        }
    }
   int i =pivot+1;
   int j = n-1;
   while(i <=j) {
    swap(arr[i], arr[j]);
    i++;
    j--;
   }

}
void print_array(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int n = 5;
    int arr[] = {1,2,5,4,3};
    next_permutation(arr, n);
    print_array(arr, n);

}