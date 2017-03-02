class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) {
            return false;
        }
        
        vector<int> mindp(n); // mindp[i] holds the minimum number of range [0... i - 1]
        mindp[0] = nums[0];
        for(int i = 1; i < n; ++i) {
            mindp[i] = min(mindp[i - 1], nums[i]);
        }
        
        stack<int> leftIndx; // leftIndx will hold the nums[i]'s leftmost greater number's indx
        leftIndx.push(0);
        leftIndx.push(1);
        
        for(int i = 2; i < n; ++i) {
            int indx = leftIndx.top();
            while(!leftIndx.empty() and nums[indx] <= nums[i]) {
                leftIndx.pop();
                if(leftIndx.empty()) {
                   indx = -1;
                   break;
                }
                indx = leftIndx.top();
            }
            if(indx > 0 and nums[indx] > nums[i] and nums[i] > mindp[indx - 1]) {
                return true;
            }
            leftIndx.push(i);
        }
        
        return false;
    }
};