#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>&arr, int i, int target) {
    if(target == 0) {
        return 1;
    }
    if(target < 0) {
        return 0;
    }
    
    int a= solve(arr, i, target-arr[i]);
    int b =solve(arr, i+1, target-arr[i]);
    int c = solve(arr, i+1, target);
    
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }


}