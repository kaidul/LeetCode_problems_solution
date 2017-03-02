class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        for(int i = 0; i < n;) {
            if(nums[i] < n and nums[i] != i) {
                swap(nums[i], nums[nums[i]]);
            } else {
                ++i;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] != i) {
                return i;
            }
        }
        return n;
    }
};