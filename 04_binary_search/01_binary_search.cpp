#include <iostream>
#include <vector> 
using namespace std;
int binary_search(vector<int> vec, int target , int size, int st, int end) {
    if(st <= end) {
        int mid = st +(end-st)/2;
        if(vec[mid] < target) {
            return binary_search(vec, target, size, mid+1, end);
        } else if(vec[mid] > target) {
            return binary_search(vec, target, size, st , mid-1);
        } else {
            return mid;
        }
    }
    return -1;
    
}

int main() {
    vector<int> vec = {2,4,5,67,88,99};
    int target = 99;
    int size = vec.size();
    int st =0; int end = size-1;
    cout << binary_search(vec, target, size, st, end) << endl;
}