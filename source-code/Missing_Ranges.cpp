class Solution {
    void output(int lower, int upper, vector<string>& result) {
        if(upper == lower) {
            result.push_back(to_string(lower));
        } else {
            result.push_back(to_string(lower) + "->" + to_string(upper));
        }
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        // case: array empty, both lower and upper inclusive
        if(nums.empty()) {
            output(lower, upper, result);
            return result;
        }
        
        // case: lower inclusive
        if(nums[0] - lower > 0) {
            output(lower, nums[0] - 1, result);
        }
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] - nums[i - 1] > 1) {
                output(nums[i - 1] + 1, nums[i] - 1, result);
            }
        }
        
        // case: upper inclusive
        if(upper - nums[nums.size() - 1] > 0) {
            output(nums[nums.size() - 1] + 1, upper, result);
        }
        
        return result;
    }
};