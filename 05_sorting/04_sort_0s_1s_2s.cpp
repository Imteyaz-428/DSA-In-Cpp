#include <iostream>
#include <vector>
using namespace std;
void sorted(int arr[], int n) {
    int low = 0;
    int mid = 0;
    int high =n-1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        } else if(arr[mid]== 1)  {
            mid++;
        } else {
            swap(arr[mid], arr[high]) ;
            high--;
        }
    }
}
void print_array(int arr[], int n) {
    for(int i=0; i<n; i++) { 
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 6;
    int arr[] = {2,2,1,0,1,2};
    sorted(arr, n);
    print_array(arr,n);
    return 0;
    
}