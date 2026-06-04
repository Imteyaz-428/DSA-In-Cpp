#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int> &arr, int size, int c,int maxdistant) {
    int stall = arr[0];
    int cows =1;
    for(int i=1; i<size; i++) {
        if((arr[i] - stall )>= maxdistant) {
            cows ++;
            stall = arr[i];
        }
        if(cows == c) {
            return true;
        }
    }
    return false;
}

int maxDistance(vector<int> &arr, int size, int c) {
    sort(arr.begin(), arr.end());
    int ans = -1;
    int sum =0;

   
    int st =1;
    int end = arr[size-1] - arr[0];
    while(st <= end) {
        int mid = st + (end -st)/2;
        if(isValid(arr, size, c , mid)) {
            ans = mid;
            st = mid+1;
        } else {
            end = mid-1;
        }
    } 
    return ans;

}

int main() {
    vector<int> arr = {1,2,8,4,9};
    int size = arr.size();
    int c = 3;
    cout << maxDistance(arr, size,c) << endl;
}