#include <iostream>
#include <vector>
using namespace std;


bool isValid(int mid, vector<int> &arr, int x) {
    int count =0;
    for(int i=0; i<arr.size(); i++) {
        if(mid > arr[i]) {
            count += (mid - arr[i]);

        }
    }
    return count < x ? true: false;
}

int main() {
    int t;
    cin >> t;
    int n,x;
    cin >> n >> x;
    while(t--) {
        vector<int> arr(n); 
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int sum =0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
        }
        int end= (sum + x)/n;
        int st =0;
        int ans =0;
        while(st <= end) {
            int mid = st + (end -st)/2;
            if(isValid(mid, arr,x)) {
                ans =mid;
                st = mid+1;
            } else {
                end = mid-1;
            }
        }
        cout << ans << endl;


    }
    

}