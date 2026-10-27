#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> arr[i][j];
        }
    }
    // for(int i=0; i<n; i++) {
    //     sort(arr[i].begin(), arr[i].end());
    // }
    long long ans1 = 0;
    long long ans2 =0;
    for(int i=0; i<n; i++) {
        if(i%2 ==0) {
            ans1 += arr[i][2];
            ans2 += arr[i][1];
        } else {
            ans1 += arr[i][1];
            ans2 += arr[i][2];
        }
    }
    cout << max(ans1, ans2);

} 