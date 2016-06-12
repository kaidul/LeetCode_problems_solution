class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int, int> exist;
        for(int i = 0; i < n; ++i) {
            if(exist.find(nums[i]) != exist.end() and i - exist[nums[i]] <= k) {
                return true;
            }
            exist[nums[i]] = i;
        }
        return false;
    }
};