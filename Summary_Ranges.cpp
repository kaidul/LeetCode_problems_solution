class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        string elem = "";
        if(nums.size() > 0) {
            elem = to_string(nums[0]) + "->";
        }

        for(int i = 1; i < nums.size(); ++i) {
            bool isRange = false;
            
            while(i < nums.size() and (i > 0 and nums[i] == nums[i - 1] + 1)) {
                ++i;
                isRange = true;
            }
            if(isRange) {
                elem += to_string(nums[i - 1]);
            } else {
                elem = elem.substr(0, elem.size() - 2);
            }
            result.push_back(elem);

            if(i < nums.size()) {
                elem = to_string(nums[i]) + "->";
            }

        }

        if(elem.size() > 0 and elem[elem.size() - 1] == '>') {
            result.push_back(elem.substr(0, elem.size() - 2));
        }

        return result;
    }
};