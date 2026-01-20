// Running Sum of 1D Array
// Concept: Prefix Sum
// Time: O(n), Space: O(1)

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};
