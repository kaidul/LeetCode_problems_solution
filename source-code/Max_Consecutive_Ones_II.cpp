class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int n = (int)nums.size();
        int cnt = 0;
        int pos = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i]) {
                cnt++;
            } else if(!nums[i] and pos == -1) {
                cnt++;
                pos = i;
            } else {
                cnt = i - pos;
                pos = i;
            }
            result = max(result, cnt);
        }
        
        return result;
    }
};