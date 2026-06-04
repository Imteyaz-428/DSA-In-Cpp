#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> arr= {9,4,20,3,10,15};
    int n = arr.size();
    int freq=0;
    int target =13;
    unordered_map<int,int>s;
    vector<int>prefixsum(n, 0);
    prefixsum[0]= arr[0];
    for(int i=1; i<n; i++) {
        prefixsum[i] = prefixsum[i-1] + arr[i];
    }
    for(int i =0; i<n; i++) {
        if(prefixsum[i] == target) {
            freq++;
        }
        int val = prefixsum[i]-target;
        if(s.find(val) != s.end()) {
            freq += s[val];
        }
        if(s.find(val) == s.end()) {
            s[prefixsum[i]] =0;
        }
        s[prefixsum[i]]++;
    }
    cout << freq << endl;

}