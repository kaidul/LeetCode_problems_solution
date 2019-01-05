// MLE for very big k and array size
class Solution {
    int maxProfit(int indx, int stock, int const k, vector<int> const& prices, vector<vector<int>>& dp) {
        if (indx >= prices.size() - 1) {
            return 0;
        }
        if (stock == k) {
            return 0;
        }
        if (dp[indx][stock] != -1) {
            return dp[indx][stock];
        }
        
        int profit = 0;
        int minPrice = prices[indx];
        for (int i = indx + 1; i < prices.size(); i++) {
            if (prices[i] > minPrice) {
                profit = max(profit, (prices[i] - minPrice) + maxProfit(i, stock + 1, k, prices, dp));    
            }
            minPrice = min(minPrice, prices[i]);
        }
        
        return dp[indx][stock] = profit;
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        k = min(k, (int)prices.size() - 1);
        vector<vector<int>> dp(prices.size(), vector<int>(k + 1, -1));
        return maxProfit(0, 0, k, prices, dp);
    }
};

// Accepted
// prune: There are atmost n / 2 transactions possible
// so if k is >= n / 2, then we can overlook the contraints of k transactions
// and can try to do as much transaction as possible
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = (int)prices.size();
        if(k >= n / 2) {
            int result = 0;
            for(int i = 1; i < n; ++i) {
                result += max(prices[i] - prices[i - 1], 0);
            }
            return result;
        }
        
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sale(k + 1, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sale[j - 1] - prices[i]);
                sale[j] = max(sale[j], buy[j] + prices[i]);
            }
        }
        
        return sale[k];
    }
};