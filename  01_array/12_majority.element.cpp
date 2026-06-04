#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int> vec , int size) {
    int freq = 0;
    vector<int> ans;
    for(int i =0; i< size; i++) {
        int curr = vec[i];
        for(int j =0; j<size; j++) {
            if(vec[j] == curr) {
                freq++;
            }
        }
        if(freq > size/2) {
            ans.push_back(curr);
            break;
        }
    }
    return ans;
}

int main() {
    vector<int> vec = {1,2,2,3,4,2,2,2};
    int size = vec.size();
    auto val = majorityElement(vec, size);
    cout << val[0] << endl;
    
}