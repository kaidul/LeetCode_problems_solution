class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = (int)arr.size();
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if((long)arr[i] - (long)arr[j] > INT_MAX or (long)arr[i] - (long)arr[j] < INT_MIN) {
                    continue;
                }
                int diff = arr[i] - arr[j];
                dp[i][diff]++;
                if(dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    result += dp[j][diff];
                }
            }
        }
        return result;
    }
};