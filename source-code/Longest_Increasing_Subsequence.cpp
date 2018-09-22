class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> I(n + 1, numeric_limits<int>::max());
        I[0] = numeric_limits<int>::min();
        int length = 0;
        for(int i = 0; i < n; ++i) {
            int left = 0;
            int right = length;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(I[mid] < nums[i]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            I[left] = nums[i];
            length = max(length, left);
        }
        return length;
    }
};
// O(n^2)
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = 0;
        if(nums.empty()) return result;
        int n = nums.size();
        vector<int>dp(n, 1);
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            result = max(result, dp[i]);
        }
        return result;
    }
};
*/