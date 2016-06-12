class Solution {
    int upperBound(vector<int> const& nums, int right, int target) {
        int left = 0;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                right = mid;
            } else if(nums[mid] <= target) {
                left = mid + 1;
            }
        }
        return left;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> sum(n, 0);
        for(int i = 0; i < n; ++i) {
            sum[i] = (i > 0 ? sum[i - 1] : 0) + nums[i];
            if(sum[i] >= target) {
                int upper_bound = upperBound(sum, i, sum[i] - target);
                minLen = min(minLen, i - upper_bound + 1);
            }
        }
        return (minLen != INT_MAX ? minLen : 0);
    }
};