class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;
        /* AC
        int Min, Max;
        Min = Max = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < Max) {
                profit += (Max - Min);
                Min = prices[i];
            }
            Max = prices[i];
        }
        profit += Max - Min;
        return profit;
        */
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > prices[i - 1])
                profit += (prices[i] - prices[i - 1]);
        }
        return profit;
    }
};