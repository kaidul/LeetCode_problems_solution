// two pointers O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int n = nums.size();
        if(n == 0) return 0;
        int i = 0, k = 0, sum = 0;
        while(i < n) {
            sum += nums[i++];
            while(sum >= target) {
                minLen = min(minLen, i - k);
                sum -= nums[k++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

// O(nlogn)
class Solution {
    // find the right-most occurance of value X such that X <= target
    int upperBound(vector<int> const& nums, int right, int target) {
        int left = 0;
        int indx = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                right = mid - 1;
            } else if(nums[mid] <= target) {
                indx = mid;
                left = mid + 1;
            }
        }
        return indx;
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
                int upper_bound = upperBound(sum, i - 1, sum[i] - target);
                minLen = min(minLen, i - upper_bound);
            }
        }
        return (minLen != INT_MAX ? minLen : 0);
    }
};