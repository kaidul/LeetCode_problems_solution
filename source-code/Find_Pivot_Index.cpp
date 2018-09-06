class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.empty())
            return -1;
        
        int n = (int) nums.size();
        vector<int> suffixSum(n + 1, 0);
        suffixSum[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffixSum[i] = nums[i] + suffixSum[i + 1];
        }
        int prefixSum = 0;
        for(int i = 0; i < n; i++) {
            if(prefixSum == suffixSum[i + 1]) {
                return i;
            }
            prefixSum += nums[i];
        }
        
        return -1;
    }
};