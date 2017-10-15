class Solution {
    int canPartitionKSubsets(vector<int>& nums, int curr, const int target, int k, int mask, unordered_map<int, unordered_map<int, unordered_map<int, int>>>& dp) {
        if(curr == target) {
            curr = 0;
            k--;
        }
        int n = (int)nums.size();
        if(k == 0 and mask == (1 << n) - 1 and curr == 0) {
            return 1;
        }
        
        if(dp[k][mask][curr]) {
            return dp[k][mask][curr];
        }
        
        for(int i = 0; i < n; i++) {
            if(!(mask & (1 << i))) {
                if(curr + nums[i] <= target) {
                    if(canPartitionKSubsets(nums, curr + nums[i], target, k, mask | (1 << i), dp) == 1) {
                        return dp[k][mask][curr] = 1;
                    }
                }
            }
        }
        return dp[k][mask][curr] = 2;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int sum = 0;
        for(int val : nums) {
            sum += val;
        }
        if(k == 1) { return true; }
        if(sum % k != 0) {
            return false;
        }
        int target = sum / k;
        int mask = 0;
        unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;
        return canPartitionKSubsets(nums, 0, target, k, mask, dp) == 1;
    }
};