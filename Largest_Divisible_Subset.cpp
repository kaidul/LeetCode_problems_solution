class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()) return result;
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int indx = 0, maxLength = dp[0];
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > maxLength) {
                maxLength = dp[i];
                indx = i;
            }
        }
        result.resize(maxLength);
        result[--maxLength] = nums[indx];
        for(int i = indx - 1; i >= 0; --i) {
            if(dp[i] + 1 == dp[indx] and nums[indx] % nums[i] == 0) {
                result[--maxLength] = nums[i];
                indx = i;
            }
        }
        return result;
    }
};