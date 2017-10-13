class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int X = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int Y = nums[0] * nums[1] * nums[n - 1];
        return max(X, Y);
    }
};