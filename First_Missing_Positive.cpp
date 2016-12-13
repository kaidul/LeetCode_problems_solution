class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // with O(n) space
        /*
        unordered_map <int, bool> exist;
        for(int i = 0; i < nums.size(); ++i) {
            exist[nums[i]] = true;
        }
        int i;
        for(i = 1; exist[i]; ++i);
        return i;
        */
        
        int n = nums.size();
        int i = 0;
        while(i < n) {
            while(nums[i] != i + 1 and nums[i] >= 1 and nums[i] <= n and nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
            ++i;
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;        
    }
};