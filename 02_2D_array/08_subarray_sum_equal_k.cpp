#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {9,4,20, 3, 10,5};
    int target = 33;
    int count =0;
    vector<int> subArr(arr.size(), 0);
    int sum =0;
    for(int i=0; i<arr.size(); i++) {
        sum += arr[i];
        subArr[i] = sum;
        if(sum == target) {
            count++;
        }

    }

    unordered_map<int, int> m;
    for(int i=0; i<arr.size(); i++) {
        int curr = subArr[i] -target;
        if(m.find(curr)  != m.end()) {
            count += m[curr];
        } 
        m[subArr[i]]++;
    }
    cout << count << endl;

}