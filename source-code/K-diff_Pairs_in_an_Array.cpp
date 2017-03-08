class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int result = 0;
        if(k < 0) return result;
        unordered_map<int, int> numMap;
        for(int i = 0; i < (int)nums.size(); i++) {
            numMap[nums[i]]++;
        }
        if(k == 0) {
            for(auto num: numMap) {
                result += (num.second >= 2);
            }
            return result;
        }
        for(auto num: numMap) {
            result += (numMap.find(num.first + k) != numMap.end());
        }
        return result;
    }
};