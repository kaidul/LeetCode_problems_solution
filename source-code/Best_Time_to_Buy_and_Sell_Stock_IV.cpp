// Memory limit exceeded (the 2D dp array seems too big)
class Solution {
public:
    int maxProfitUtils(int cnt, int idx, int profit, int k, vector<int>& prices, vector<vector<int>>& dp) {
        if(cnt > k) {
            return INT_MAX;
        }
        if(idx == (int)prices.size() or cnt == k) {
            return profit;
        }
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        
        int profitUntil, profitUntilPrev;
        int Min = prices[idx];
        profitUntilPrev = 0;
        int ret = 0;
        
        ret = max(ret, profit + maxProfitUtils(cnt, idx + 1, 0, k, prices, dp));
        for(int j = 1; j < (int)prices.size() - idx; ++j) {
            profitUntil = max(profitUntilPrev, prices[j + idx] - Min);
            if(prices[j + idx] - Min > 0) {
                ret = max(ret, profit + maxProfitUtils(cnt + 1, j + idx + 1, profitUntil, k, prices, dp));
            } else {
                ret = max(ret, profit + maxProfitUtils(cnt, j + idx + 1, profitUntil, k, prices, dp));
            }
            profitUntilPrev = profitUntil;
            Min = min(Min, prices[j + idx]);
        }
        return dp[idx][cnt] = ret;
    }
    
    
    int maxProfit(int k, vector<int> &prices) {
        int n = (int)prices.size();
        k = min(k, n / 2);
        vector< vector<int> > dp(n, vector<int>(k + 1, -1));
        if(n < 2) return 0;
        int r = maxProfitUtils(0, 0, 0, k, prices, dp);
        return r;
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