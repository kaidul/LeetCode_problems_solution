class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = (int)nums.size();
        int sum = 0;
        freq[sum]++;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            cnt += freq[sum - k];
            freq[sum]++;
        }
        return cnt;
    }
};