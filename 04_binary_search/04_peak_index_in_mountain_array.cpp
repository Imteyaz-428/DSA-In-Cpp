#include <iostream>
#include <vector>
using namespace std;
int mountain_array(vector<int> arr, int size) {
    int st = 0; 
    int end= size -1;
    while(st <= end) {
        int mid = st + (end-st)/2;
        if(arr[mid-1] < arr[mid]  && arr[mid]  > arr[mid+1])  {
            return mid;
        } else if(arr[mid] < arr[mid-1]) {
            st = mid+1;
        } else {
            end = mid-1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1,3,5,7,5,4,2};
    int size = arr.size();
    cout << mountain_array(arr, size) << endl;
}