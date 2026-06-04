#include <iostream>
#include <vector>
using namespace std;
// the problem state that find the floor value of sqauare root of an integer n.
// brute force 
int bruteSqRoot(int n) {
    int ans = -1;
    for(int i=1; i<=n;i++) {
        if(i *i <= n) {
            ans =i;
        } else {
            break;
        }
    }
    return ans;
}
// optimal approach
// time comp :- O(logn)
int sqRoots(int n) {
    int  ans = -1;
    int st =1;
    int end= n;
    while(st <= end) {
        int mid = st + (end-st)/2;
        if(mid <= n/mid) {
            ans = mid;
            st = mid+1;
        } else {
            end = mid-1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "enter your input :" ;
    cin >> n;
    cout << "sqroot :" << sqRoots(n) << endl;
}