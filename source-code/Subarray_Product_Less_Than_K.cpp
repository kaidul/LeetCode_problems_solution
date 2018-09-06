class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.empty())
            return 0;
        int result = 0;
        int product = 1;
        int left = 0, right = 0;
        while(right < nums.size()) {
            product *= nums[right];
            while(left <= right and product >= k) {
                product /= nums[left++];
            }
            result += (right - left + 1);
            right++;
        }
        
        return result;
    }
};