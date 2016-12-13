class Solution {
    int combinationSum4Util(int indx, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if(sum == 0) {
            return 1;
        }
        if(dp[indx][sum] != -1) return dp[indx][sum];
        int ret = 0;
        for(int i = 0; i < (int)nums.size(); ++i) {
            if(sum - nums[i] >= 0) {
                ret += combinationSum4Util(i, sum - nums[i], nums, dp);
            }
        }
        return ret;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        // Big TLE
        /*
        if(nums.empty()) return 0;
        vector<vector<int>> dp((int)nums.size(), vector<int>(target + 1, -1));
        return combinationSum4Util(0, target, nums, dp);
        */
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; ++i) {
            for(int j = 0; j < (int)nums.size(); ++j) {
                if(i - nums[j] >= 0) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};