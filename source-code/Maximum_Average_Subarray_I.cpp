class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if(k > n) return 0;
        long long sum = 0LL;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double result = (double)sum / k;
        for(int i = k; i < n; i++) {
            sum -= nums[i - k];
            sum += nums[i];
            result = max(result, (double)sum / k);
        }
        return result;
    }
};