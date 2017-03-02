class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        /*
        // O(n^2) solution TLE
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }
        int maxLen = 0;
        for(int i = nums.size() - 1; i >= 0; --i) {
            int length = i + 1;
            if(nums[i] == k) {
                maxLen = max(maxLen, length);
                continue;
            }
            if(length <= maxLen) {
                return maxLen;
            }
            for(int j = 0; j < i; ++j) {
                length = i - j;
                if(length <= maxLen) {
                    break;
                }
                if(nums[i] - nums[j] == k) {
                    maxLen = max(maxLen, length);
                    break;
                }
            }
        }
        return maxLen;
        */
        int n = nums.size();
        unordered_map <int, int> hashSum;
        vector<int> subSum(n + 1, 0);
        hashSum[0] = 0;
        int maxLen = 0;
        for(int i = 1; i <= n; ++i) {
        	subSum[i] = subSum[i - 1] + nums[i - 1];
        	if(hashSum.find(subSum[i] - k) != hashSum.end()) {
        		maxLen = max(maxLen, i - hashSum[subSum[i] - k]);
        	}
        	if(hashSum.find(subSum[i]) == hashSum.end()) {
        		hashSum[subSum[i]] = i;
        	}
        }
        return maxLen;
    }
};