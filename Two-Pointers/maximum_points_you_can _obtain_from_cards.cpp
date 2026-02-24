class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int idx =0;
        int lsum =0;
        for(int i=0;i <k; i++) {
            lsum += arr[i];
            idx++;
        }
        idx--;
        int maxsum = lsum;
        int r = n-1;
        int p = k;
        int sum =0;
        int rsum =0;
        while(idx >= 0 && r >=0 && p >0) {
            p--;
            
            lsum = lsum-arr[idx--];
            rsum = rsum + arr[r--];
            sum = lsum + rsum;
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};
