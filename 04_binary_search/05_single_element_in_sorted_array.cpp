#include <iostream>
#include <vector>
using namespace std;
int single_element(vector<int> arr, int size) {
    int st = 0; 
    int end = size-1;
    while(st <= end) {
        int mid = st+ (end-st)/2;
        if(arr[mid -1]  != arr[mid] && arr[mid] != arr[mid+1]){
            return mid;
        }
        if(mid %2 == 0) {
            if(arr[mid] == arr[mid+1]) {
                st = mid+1;
            } else{
                end = mid-1;
            }
        } else{
            if(arr[mid] == arr[mid-1]) {
                st = mid+1;
            } else{
                end = mid-1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1,1,2,2,3,3,4,5,5};
    int size = arr.size();
    cout << single_element(arr, size) << endl;

}