class Solution {
    int countLIS(int indx, vector<int>& nums, vector<int>& dp) {
        if(dp[indx] == 1) {
            return 1;
        }
        int count = 0;
        for(int i = indx - 1; i >= 0; i--) {
            if(nums[i] < nums[indx] and dp[i] + 1 == dp[indx]) {
                count += countLIS(i, nums, dp);
            }
        }
        return count;
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = (int)nums.size();
        vector<int> dp(n, 1);
        dp[0] = 1;
        int maxLength = dp[0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        vector<int> lastIndx;
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxLength) {
                lastIndx.push_back(i);
            }
        }
        int result = 0;
        for(int i = 0; i < lastIndx.size(); i++) {
            result += countLIS(lastIndx[i], nums, dp);
        }
        
        return result;
    }
};