#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>arr(n);
    unordered_map<int, int> m;
    m.reserve(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    int count =0;
    // for(int i=0; i<n; i++) {
    //     if(m.find(arr[i] )!= m.end()) {
    //         ans = max(ans,count);
    //         count =1;
    //         m = unordered_map<int, int>();
            
    //     }  else {
    //         m[arr[i]]++;
    //         count++;
    //     }
    // }
    // cout << ans << endl;
    int left =0;
    int right =0;
    while(right >= left && right < n) {
        m[arr[right]]++;
        while(m[arr[right]] > 1) {
            m[arr[left]]--;
            if(m[arr[left]] == 0) {
                m.erase(arr[left]);
            }
            left++;
        }
        int len = right - left  +1 ;
        ans = max(ans, len);
        
        right++;
    }
    cout << ans << endl;
    

}