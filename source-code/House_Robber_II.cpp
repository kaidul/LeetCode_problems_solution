class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) return 0;
        if(n == 1) return nums[0];
        int first, second;
        int a = 0, b = nums[0];
        for(int i = 1; i < n - 1; ++i) {
            int tmp = b;
            b = max(b, a + nums[i]);
            a = tmp;
        }
        first = b;
        a = 0;
        b = nums[1];
        for(int i = 2; i < n; ++i) {
            int tmp = b;
            b = max(b, a + nums[i]);
            a = tmp;
        }
        second = b;
        return max(first, second);
    }
};