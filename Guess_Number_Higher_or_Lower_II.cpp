class Solution {
    int getMoneyAmountDp(int left, int right, vector<vector<int>>& dp) {
        if(left >= right) {
            return 0;
        }
        int& ret = dp[left][right];
        if(ret != -1) return ret;
        ret = INT_MAX;
        for(int x = left; x <= right; ++x) {
            ret = min(ret, x + max(getMoneyAmountDp(left, x - 1, dp), getMoneyAmountDp(x + 1, right, dp)));
        }
        
        return ret;
    }
    
public:
    int getMoneyAmount(int n) {
        // bottom-up
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        for(int i = 0; i <= n; ++i) {
            dp[i][i] = 0;
        }
        for(int len = 2; len <= n; ++len) {
            for(int left = 1; left + len - 1 <= n; ++left) {
                int right = left + len - 1;
                for(int x = left; x <= right; ++x) {
                    int lhs = 0, rhs = 0;
                    if(x > left) {
                        lhs = dp[left][x - 1];
                    }
                    if(x < right) {
                        rhs = dp[x + 1][right];
                    }
                    dp[left][right] = min(dp[left][right], x + max(lhs, rhs));
                }
            }
        }
        return dp[1][n];
        
        // top-down
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return getMoneyAmountDp(1, n, dp);
    }
};