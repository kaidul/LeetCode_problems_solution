// DP O(n sqrt(n))
class Solution {
public:
    int numSquares(int n) {
        const int MAX = n + 1;
        vector<int> dp(MAX, MAX);
        dp[0] = 0;
        for(int i = 1; (i * i) <= n; ++i) {
            int k = i * i;
            for(int j = k; j <= n; ++j) {
                dp[j] = min(dp[j - k] + 1, dp[j]);
            }
        }
        
        return dp[n];
    }
};