class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = (int)nums.size();
        for (int left = 0, right = 0; right < n; left++, right++) {
            while (right + 1 < n and nums[right + 1] == nums[right] + 1) {
                right++;
            }
            int rangeLength = right - left + 1;
            string range;
            if (rangeLength == 1) {
                range = to_string(nums[left]);
            } else {
                range = to_string(nums[left]);
                range += "->";
                range += to_string(nums[right]);
            }
            result.push_back(range);
            left = right;
        }
        
        return result;
    }
};