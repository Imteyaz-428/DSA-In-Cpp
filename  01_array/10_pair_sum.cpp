#include <iostream>
#include <vector>
using namespace std;

// print the index of the element which have sum equal to target in pair form
vector<pair<int,int>> pairsum(vector<int>vec, int size, int target) {
    vector<pair<int, int>>ans;
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(vec[i] + vec[j] == target) {
                ans.push_back({vec[i],vec[j]});
            }
        }
    }
    return ans;
}

int main() {
    vector<int>vec = {1,2,3,4,5};
    int size = vec.size();
    int target = 7;
    auto arr = pairsum(vec, size, target);
    for(auto val : arr) {
      cout << val.first << " ," << val.second << endl;
    }
}