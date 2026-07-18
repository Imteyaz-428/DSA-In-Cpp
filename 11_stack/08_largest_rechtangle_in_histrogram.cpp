#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;
void left_smaller(vector<int>& arr,stack<int>& s, vector<int>& temp) {
    for(int i=arr.size()-1; i>=0; i--) {
        while(s.size()> 0 && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if(s.empty()) {
            temp[i] = -1;

        } else {
            temp[i] = s.top();
        }
        s.push(i);
    }
    while(!s.empty()) {
        s.pop();
    }
    
    
}
void right_smaller(vector<int>& arr, stack<int>& s  , vector<int>& right) {
    for(int i =0; i<arr.size(); i++) {
        while(s.size() >0 && arr[s.top()]>= arr[i]) {
            s.pop();
        }
        if(s.empty()) {
            right[i] = arr.size();
        } else {
            right[i] = s.top();
        }
        s.push(i);
    }
}

int largest(vector<int>& arr) {
    stack<int> s;
   
    vector<int> temp(arr.size(),0);
    vector<int> right(arr.size(),0);
    right_smaller(arr, s, right);
    left_smaller(arr, s, temp);

    int maxsum = 0;
    for(int i =0; i<arr.size(); i++) {
        int width = temp[i] - right[i] -1;
        int area = arr[i] * width;
        maxsum = max(maxsum, area);


    }
    return maxsum;

}

int main() {
    vector<int> arr = {2,1,5,6,2,3};

    int ans = largest(arr);
    cout << ans << endl;

}