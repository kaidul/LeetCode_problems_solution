class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();

        vector<int> prefixIndxDp(n); // prefixIndxDp[i] = starting index of subarray of size k with maximum sum within [0...i]
        vector<int> prefixSumDp(n, 0); // prefixSumDp[i] = maximum sum of subarray of size k within [0...i]
        int currSum = 0;
        for(int i = 0; i < k; i++) {
            currSum += nums[i];
        }
        int sum = currSum;
        prefixSumDp[k - 1] = currSum;
        prefixIndxDp[k - 1] = 0;

        for(int i = k; i < n; i++) {
            currSum -= nums[i - k];
            currSum += nums[i];
            if(currSum > sum) {
                sum = currSum;
                prefixIndxDp[i] = i - k + 1;
                prefixSumDp[i] = currSum;
            } else {
                prefixSumDp[i] = prefixSumDp[i - 1];
                prefixIndxDp[i] = prefixIndxDp[i - 1];
            }
        }

        vector<int> suffixIndxDp(n);
        vector<int> suffixSumDp(n, 0);
        currSum = 0;
        for(int i = n - 1; i >= n - k; i--) {
            currSum += nums[i];
        }
        sum = currSum;
        suffixSumDp[n - k] = currSum;
        suffixIndxDp[n - k] = n - k;
        for(int i = n - k - 1; i >= 0; i--) {
            currSum -= nums[i + k];
            currSum += nums[i];
            if(currSum > sum) {
                sum = currSum;
                suffixIndxDp[i] = i;
                suffixSumDp[i] = currSum;
            } else {
                suffixSumDp[i] = suffixSumDp[i + 1];
                suffixIndxDp[i] = suffixIndxDp[i + 1];
            }
        }

        vector<int> result;
        int midSum = 0;
        for(int i = k; i < k + k; i++) {
            midSum += nums[i];
        }
        int maxSum = 0;
        for(int i = k; i < n - k - k + 1; i++) {
            if(prefixSumDp[i - 1] + midSum + suffixSumDp[i + k] > maxSum) {
                maxSum = prefixSumDp[i - 1] + midSum + suffixSumDp[i + k];
                result = vector<int>{prefixIndxDp[i - 1], i, suffixIndxDp[i + k]};
            }
            midSum -= nums[i];
            midSum += nums[i + k];
        }

        return result;
    }
};