#include <iostream>
#include <vector>
using namespace std;
 
// time comp :- O(n)
// space comp :- O(n)
bool isSorted(vector<int> arr, int n) {
    if(n == 1 || n == 0) {
        return true;
    }
    
    return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}

int main() {
    vector<int> arr = {1,2,2,4,5};
    int n = 5;
    cout << isSorted(arr, n) << endl;

}