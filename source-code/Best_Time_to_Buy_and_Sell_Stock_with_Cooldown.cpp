class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = (int)prices.size();
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 0;
        for(int i = 2; i <= n; ++i) {
            int profit = prices[i - 1] - prices[i - 2];
            dp[i] = max(dp[i - 1] + profit, dp[i - 2]);
            dp[i - 1] = max(dp[i - 1], dp[i - 2]);
        }
        return max(dp[n - 1], dp[n]);
    }
};

// reducing memory
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = (int)prices.size();
        int incl = 0, excl = 0;
        for(int i = 1; i < n; ++i) {
            int profit = prices[i] - prices[i - 1];
            int tmp = max(incl + profit, excl);
            excl = max(incl, excl);
            incl = tmp;
        }
        return max(incl, excl);
    }
};