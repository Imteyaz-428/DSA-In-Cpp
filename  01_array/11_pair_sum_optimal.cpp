#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pairSum(vector<int>vec, int size, int target) {
    vector<vector<int>> ans;
    int st = 0;
    int end = size-1; 
    while(st <end) {
        if(vec[st] + vec[end] < target) {
            st++;
        } else if(vec[st] + vec[end] > target) {
            end--;
        } else {
            ans.push_back({vec[st], vec[end]});
            st++;
            end--;
        }
    }
    return ans;
}

int main() {
    vector<int>vec = {1,2,3,4,5};
    int size = vec.size();
    int target = 9;
    auto val = pairSum(vec, size, target);
    for(auto i : val) {
        for(int j : i) {
            cout << j  << " ,";
        }
        cout << endl;
    }
    
}