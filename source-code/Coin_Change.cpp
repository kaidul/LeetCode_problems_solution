class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int MAX = amount + 1;
        vector<int> dp(amount + 1, MAX);
    	dp[0] = 0;
    	for(int i = 0, coinNo = coins.size(); i < coinNo; ++i) {
    		for(int j = coins[i]; j <= amount; ++j) {
    			dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
    		}
    	}
    	return dp[amount] != MAX ? dp[amount] : -1;
    }
};