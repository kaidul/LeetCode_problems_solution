class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0;
        if(n == 0) return 0;
        long missing = 1L;
        int i = 0;
        while(missing <= n) {
            if(i < (int)nums.size() and nums[i] <= missing) {
                missing += nums[i++];
            } else {
                missing += missing;
                patch++;
            }
        }
        return patch;
    }
};