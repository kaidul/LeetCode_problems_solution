// decomposing into subset problem
// iterative dp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   

    int subsetSum(vector<int>& nums, int sum) {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];       
            }
        }
        return dp[sum];
    }
};

// recursive dp O(n^2) space
class Solution {
    int findTargetSumWays(int indx, vector<int>& nums, int sum, unordered_map<int, unordered_map<int, int>>& dp) {
        if(indx == (int)nums.size()) {
            return (sum == 0);
        }
        if(dp.count(indx) and dp[indx].count(sum)) {
            return dp[indx][sum];
        }
        int ret = 0;
        ret += findTargetSumWays(indx + 1, nums, sum + nums[indx], dp);
        ret += findTargetSumWays(indx + 1, nums, sum - nums[indx], dp);

        return dp[indx][sum] = ret;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = (int)nums.size();
        unordered_map<int, unordered_map<int, int>> dp;
        return findTargetSumWays(0, nums, S, dp);
    }
};