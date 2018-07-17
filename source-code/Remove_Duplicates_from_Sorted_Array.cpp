class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0) return 0;
        int left = 0, right = 0;
        while(right < n) {
            if(nums[left] != nums[right]) {
                nums[++left] = nums[right];
            }
            right++;
        }
        return left + 1;
    }
};