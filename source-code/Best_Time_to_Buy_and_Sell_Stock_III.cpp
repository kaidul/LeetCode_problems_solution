// using prefix sum-suffix sum kinda approach
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n < 1) return 0;
        vector<int> profitUntil(n), profitFrom(n);
        profitUntil[0] = 0;
        int Min = prices[0];
        for(int i = 1; i < n; ++i) {
            profitUntil[i] = max(profitUntil[i - 1], prices[i] - Min);
            Min = min(Min, prices[i]);
        }
        int Max = prices[n - 1];
        profitFrom[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            profitFrom[i] = max(profitFrom[i + 1], Max - prices[i]);
            Max = max(Max, prices[i]);
        }
        int result = 0;
        for(int i = 0; i < n; ++i) {
            result = max(result, profitUntil[i] + profitFrom[i]);
        }
        return result;
    }
};

// using dp
class Solution {
public:
    int maxProfitUtils(int cnt, int idx, int profit, vector<int>& profitFrom, vector<int>& prices, vector<vector<int>>& dp) {
        if(idx == (int)prices.size() or cnt == 1) {
            return dp[idx][cnt] = profit + profitFrom[idx - 1];
        }
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        int profitUntil[(int)prices.size() - idx];
        int Min = prices[idx];
        profitUntil[0] = 0;
        for(int j = 1; j < (int)prices.size() - idx; ++j) {
            profitUntil[j] = max(profitUntil[j - 1], prices[j + idx] - Min);
            Min = min(Min, prices[j + idx]);
        }
        int ret = 0;
        for(int i = idx; i < (int)prices.size(); ++i) {
            ret = profit + max(ret, maxProfitUtils(cnt + 1, i + 1, profitUntil[i - idx], profitFrom, prices, dp));
        }
        return dp[idx][cnt] = ret;
    }
    
    
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector< vector<int> > dp(n + 1, vector<int>(3, -1));
        if(n < 2) return 0;
        vector<int> profitFrom(n);
        int Max = prices[n - 1];
        profitFrom[n - 1] = 0;
        for(int i = n - 2; i >= 0; --i) {
            profitFrom[i] = max(profitFrom[i + 1], Max - prices[i]);
            Max = max(Max, prices[i]);
        }
        return maxProfitUtils(0, 0, 0, profitFrom, prices, dp);
    }
};

// another dp approach
class Solution {
    int maxProfit(int indx, int stock, vector<int> const& prices, vector<vector<int>>& dp) {
        if (indx >= prices.size() - 1) {
            return 0;
        }
        if (stock == 2) {
            return 0;
        }
        if (dp[indx][stock] != -1) {
            return dp[indx][stock];
        }
        
        int profit = 0;
        int minPrice = prices[indx];
        for (int i = indx + 1; i < prices.size(); i++) {
            if (prices[i] > minPrice) {
                profit = max(profit, (prices[i] - minPrice) + maxProfit(i, stock + 1, prices, dp));    
            }
            minPrice = min(minPrice, prices[i]);
        }
        
        return dp[indx][stock] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(3, -1));
        return maxProfit(0, 0, prices, dp);
    }
};