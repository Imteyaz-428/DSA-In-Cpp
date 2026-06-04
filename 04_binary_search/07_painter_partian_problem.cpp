#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> arr, int size, int n, int m, int maxtime) {
    int painter= 1;
    int time =0;
    for(int i =0; i<size; i++) {
        if(arr[i] + time <= maxtime) {
            time += arr[i];
        } else{
            painter++;
            time = arr[i];
        }
    }
    return painter <= m;
}
int minimum_timetopaint(vector<int> arr, int size,int n, int m) {
    int ans = -1;
    int sum =0;
    int maxSum = INT_MIN;
    for(int i=0; i<size; i++) {
        sum += arr[i];
        maxSum = max(maxSum, arr[i]);
    }
   int st = maxSum;
   int end = sum;
    while(st <= end) {
        int mid = st +(end-st)/2;
        if(isValid(arr, size,n, m, mid)){
            ans= mid;
            end= mid-1;
        } else{
            st= mid+1;
        }
    }
    return ans;
}

int main() {
    int n=4;
    int m= 2;
    vector<int> arr = {40,30,10,20};
    int size= arr.size();
    cout << minimum_timetopaint(arr, size, n, m) << endl;

}