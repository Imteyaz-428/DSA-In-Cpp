#include <iostream>
#include <vector>
using namespace std;
 
int rotated_array(vector<int> arr, int size, int target) {
    int st =0; 
    int end = size -1;
    while(st <= end) {
        int mid = st+ (end-st)/2;
        if(arr[mid] == target) {
            return mid;
        }
        if(arr[st] <= arr[mid]) {
            if(arr[st] <= target &&  target <= arr[mid]) { //left part 
                end = mid-1;
            } else{
                st = mid+1;
            }
        } else {
            if(arr[mid] <= target &&  target <= arr[end])  {
                st = st+1;
            } else {
                end = end-1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {4,5,6,7,1,2,3};
    int size = arr.size();
    int target = 3;
    cout << rotated_array(arr, size, target) << endl;
    return 0;

}