#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> arr, int n , int m, int size, int maxbook) {
    int st = 1;
    int pages = 0;
    for(int i =0 ; i<size; i++) {
        if(arr[i] > maxbook) {
            return false;
        }
        if(arr[i] + pages <= maxbook) {
            pages += arr[i];

        } else {
            st++;
            pages = arr[i];
        }
    }
    return m < st ? false : true;
}
int allocated_books(vector<int> arr, int n, int m, int size) {

    if(m > n) {
        return -1;
    }
    int st = 0; 
    int ans = -1;
    int sum = 0;
    for(int i =0; i<size; i++) {
        sum += arr[i];
    }
    int end = sum;
    while(st <= end) {
        int mid = st + (end-st)/2;
        if(isValid(arr, n,m, size, mid)) {
            ans = mid;
            end = mid-1;
        } else {
            st = mid+1;
        }
    }
    return ans;
}

int main() {
    int n =4;
    int m= 3;
    vector<int> arr = {2,4,3,1};
    int size =arr.size();
    cout << allocated_books(arr, n,m, size) << endl;
}