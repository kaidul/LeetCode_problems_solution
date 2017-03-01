class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> indxMap;
        int sum = 0;
        indxMap[sum] = -1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(k != 0) sum %= k;
            if(indxMap.count(sum)) {
                if(i - indxMap[sum] >= 2) {
                    return true;    
                }
            } else {
                indxMap[sum] = i;
            }
        }
        return false;
    }
};