class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int changed = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                if(changed > 0) {
                    return false;
                }
                if(i - 1 >= 0) {
                    if(nums[i + 1] >= nums[i - 1]) {
                        nums[i] = nums[i - 1];
                    } else if(nums[i + 1] < nums[i - 1]) {
                        nums[i + 1] = nums[i];
                    }
                } else {
                    nums[i] = nums[i + 1]; 
                }
                ++changed;
            }
        }
        return true;
    }
};