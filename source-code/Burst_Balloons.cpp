class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = (int)nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp((int)nums.size(), vector<int>((int)nums.size(), 0));
        
        for(int len = 1; len <= n; ++len) {
            for(int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                // calculate which balloon to burst LAST that will give us the most coins for [left, right] 
                for(int k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
        }
        
        return dp[1][n];
    }
};