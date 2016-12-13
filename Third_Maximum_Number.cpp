class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.empty()) return 0;
        long max = LONG_MIN, mid = LONG_MIN, min = LONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if(x == max or x == mid or x == min)
                continue;
            
            if(x > max) {
                min = mid;
                mid = max;
                max = x;
    
            } else if(x > mid) {
                min = mid;
                mid = x;
    
            } else if(x > min) {
                min = x;
            }
        }
        return (int)(min == LONG_MIN ? max : min);
    }
};