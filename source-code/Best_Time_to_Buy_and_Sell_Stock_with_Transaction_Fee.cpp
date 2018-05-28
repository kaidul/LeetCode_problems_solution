class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = (int)prices.size();
        if(n == 0) return 0;
        vector<int> buy(n), sell(n), hold(n), skip(n);
        
        buy[0] = -prices[0];
        hold[0] = -prices[0];
        sell[0] = skip[0] = 0;
        
        for(int i = 1; i < n; i++) {
            buy[i] = max(skip[i - 1], sell[i - 1]) - prices[i];
            skip[i] = max(skip[i - 1], sell[i - 1]);
            hold[i] = max(hold[i - 1], buy[i - 1]);
            sell[i] = max(hold[i - 1], buy[i - 1]) + prices[i] - fee;
        }
        
        return max(buy[n - 1], max(skip[n - 1], max(hold[n - 1], sell[n - 1])));
    }
};
