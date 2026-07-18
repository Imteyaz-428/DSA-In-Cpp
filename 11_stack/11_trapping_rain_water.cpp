#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//naive approach to find out the trapping of rain water
//time complexity = O(n^2)
int main() {
    vector<int> arr = {4,2,0,3,2,5};
    int n = arr.size();
    // this the first approach which comes in time complexity of O(n^2)
    vector<int> temp(n,0);
    for(int i =1; i<n-1; i++) {
        int index =i, sum1=0, sum2=0;
        for(int j=index;j>=0; j--) {
            sum1= max(sum1, arr[j]);
        }
        for(int j=index; j<n; j++) {
            sum2= max(sum2, arr[j]);
        }
        int total= min(sum1, sum2);
        temp[i] = total - arr[i] ;
    }
    int sum =0;
    for(int i=0; i<n; i++) {
        sum =  sum +temp[i];
    }
    cout << sum << endl;

    // this is the second approach but in this case the time complexity is optimized but space complexiy is O(n)
    vector<int> left(n,0);
    stack<int> s;

    for(int i=0; i<n; i++) {
        while(s.size()>0 && arr[i] > s.top()) {
            s.pop();
        }
        if(s.empty()) {
            left[i] = arr[i];
        } else {
            left[i] = s.top();
        }

        if(s.size() ==0) {
            s.push(arr[i]);
        }
    }
    vector<int> right(n,0);
    for(int i =n-1; i>=0; i--) {
        while(s.size() >0 && arr[i] > s.top()) {
            s.pop();
        }

        if(s.empty()) {
            right[i] = arr[i];
        } else {
            right[i] = s.top();
        }
        if(s.size()==0)  {
            s.push(arr[i]);
        }
    }
    vector<int> water(n,0);
    for(int i=0; i<n; i++) {
        int total = min(left[i], right[i]);
        water[i] =total -arr[i];

    }
    int sum3 =0; 
    for(int i=0; i<n; i++) {
        sum3 += water[i];
    }
    cout << sum << endl;

    // this is the third and final approach which comes in time complexity of O(n) and space O(1)
    int l=0;
    int r=n-1;
    int ans=0;
    int leftmax=0, rightmax=0;
    while(l<r) {
        leftmax = max(leftmax, arr[l]);
        rightmax= max(rightmax, arr[r]);

        if(leftmax> rightmax) {
            ans += (rightmax- arr[r]);
            r--;
        } else {
            ans += (leftmax - arr[l]);
            l++;
        }
    }
    cout << ans << endl;

    
}