class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        if(prices.size() < 2) return profit;
        int Min = prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            profit = max(profit, prices[i] - Min);
            Min = min(Min, prices[i]);
        }
        return profit;
    }
};