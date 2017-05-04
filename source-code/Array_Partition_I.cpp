class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i += 2) {
            result += nums[i];
        }
        return result;
    }
};