class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = (int)nums.size();
        for(int i = 0 ; i < n; ++i) {
            sum += nums[i];
        }
        if(sum & 1) {
            return false;
        }
        sum >>= 1;
        vector<bool> dp(sum + 1, 0);
        dp[0] = true;
        for(int i = 0; i < n; ++i) {
            for(int j = sum; j >= 0; --j) {
                if(j - nums[i] >= 0) {
                    dp[j] = dp[j] | dp[j - nums[i]];
                }    
            }
        }
        return dp[sum];
    }
};