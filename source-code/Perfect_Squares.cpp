// top-down
class Solution {
    int numSquares(int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (dp[n] != INT_MAX) {
            return dp[n];
        }
        for (int i = 1; i * i <= n; i++) {
            int sqr = i * i;
            dp[n] = min(dp[n], 1 + numSquares(n - sqr, dp));
        }
        
        return dp[n];
    }
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        return numSquares(n, dp);
    }
};

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