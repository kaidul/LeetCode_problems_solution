class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> freq;
        int n = (int)nums.size();
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        int result = 0;
        for(auto iter = freq.begin(); iter != freq.end(); iter++) {
            if(freq.count(iter->first + 1)) {
                result = max(result, iter->second + freq[iter->first + 1]);
            }
        }
        return result;
    }
};