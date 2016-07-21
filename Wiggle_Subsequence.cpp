class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = (int)nums.size();
        vector<int> pos(n, 1);
        vector<int> neg(n, 1);
        int maxLength = max(pos[0], neg[0]);
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    pos[i] = max(pos[i], neg[j] + 1);
                } else if(nums[i] < nums[j]) {
                    neg[i] = max(neg[i], pos[j] + 1);
                }
            }
            maxLength = max(pos[i], neg[i]);
        }
        
        return maxLength;
    }
};