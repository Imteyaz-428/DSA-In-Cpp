#include <iostream>
#include <vector>
#include <stack>
using namespace std;



int main() {
    vector<int> height= {3,6,5,4,2};
    int n=height.size();
    vector<int> temp(n,0);
    stack<int> s;

    for(int i=n-1; i>=0; i--) {
        while(s.size() >0 && height[i] >= s.top() ) {
            s.pop();
        }
        if(i!=n-1) {
            if(s.empty()) {
                temp[i] = -1;
            } else {
                temp[i] = s.top();
            }
        }
        s.push(height[i]);

    }
    temp[n-1] = -1;
    int ans = height[n-1];
    for(int i =0; i<n-1; i++) {
        if(height[i] >ans) {
            temp[n-1] = height[i];
            break;
        }
    }
    for(int i: temp) {
        cout << i << " ";
    }
    cout << endl;
}