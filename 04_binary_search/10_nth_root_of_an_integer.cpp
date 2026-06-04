#include <iostream>
#include <vector>
using namespace std;
// the problem is that there is two number n and m given . you have to find the nth root of m. if nth root not present then return -1.

// brute force approach
// time comp: - O(n * m)
int brute_nth_root(int m, int n) {
    
    for(int i=1; i<=m; i++) {
        long long ans = 1;
        for(int j=1; j<=n; j++) {
            ans *= i;
        } 
        if(ans == m) {
            return i;
        }
        if(ans > m) {
            break;
        }
    }
    return -1;
}

// optimal approach
// time comp :- O(n * logm)
int nth_root(int m, int n) {
    int st =1;
    int end = m;
    while(st <= end) {
        int mid = st+ (end -st)/2;
        long long ans =1;
        for(int i=0; i<n; i++) {
            ans *= mid;
            if(ans > m) {
                break;
            }
        }
        if(ans == m) {
            return mid;
        } else if(ans < m) {
            st = mid+1;
        } else {
            end = mid-1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "please enter the value of n :" ;
    cin >> n;
    cout << endl;
    int m;
    cout << "please enter the integer value m :";
    cin >> m;
    cout << nth_root(m,n) << endl;


}