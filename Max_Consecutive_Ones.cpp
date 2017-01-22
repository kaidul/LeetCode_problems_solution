class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int n = (int)nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i]) {
                cnt++;
                result = max(result, cnt);
            } else {
                cnt = 0;
            }
        }
        return result;
    }
};