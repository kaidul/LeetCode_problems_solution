class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 0;
        int i = 0;
        while(i < nums.size()) {
            int currLen = 0;
            int prev = nums[i++];
            currLen++;
            while(i < nums.size() and nums[i] > prev) {
                prev = nums[i++];
                currLen++;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};