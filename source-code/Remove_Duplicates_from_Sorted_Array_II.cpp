class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int len = 2;
        for(int i = 2; i < nums.size(); i++) {
            if(nums[len - 2] < nums[i]) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};