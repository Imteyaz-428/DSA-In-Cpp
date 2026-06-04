#include <iostream>
#include <vector>
using namespace std;

vector<int> product_array(vector<int> nums ) {
    vector<int>ans(nums.size());
    for(int i =0;i<nums.size(); i++) {
        int product = 1;
        for(int j =0; j<nums.size(); j++) {
            if(j != i) {
                product *= nums[j];
            }
        }
        ans[i] = product;
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4};
    auto val = product_array(nums);
    for(auto i : val) {
        cout << i << endl;
    }
}