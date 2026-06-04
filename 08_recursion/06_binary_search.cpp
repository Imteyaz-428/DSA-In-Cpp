#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> arr, int n , int target, int st, int end) {
    int mid = st + (end-st)/2;
    if(arr[mid] == target) {
        cout << "target is found and the index is :";
        return mid;
    } else if(arr[mid < target]) {
        return binary_search(arr,n, target, mid+1 , end);
    } else {
        return binary_search(arr, n, target, st, mid-1);
    }
}

int main() {
    vector<int> arr = {3,5,7,9,22,54,65};
    int n = arr.size();
    int target = 54;
    int st = 0;
    int end = n-1;
    cout << binary_search(arr, n, target, st, end) <<endl;
}