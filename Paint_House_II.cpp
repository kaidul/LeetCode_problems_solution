class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int n = (int)costs.size();
        int m = (int)costs[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        
        for(int i = 0; i < m; ++i) {
            dp[0][i] = costs[0][i];
        }
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int cost = INT_MAX;
                for(int k = 0; k < m; ++k) {
                    if(k == j) { continue; }
                    cost = min(cost, dp[i - 1][k]);
                }
                dp[i][j] = costs[i][j] + cost;
            }
        }
        int result = INT_MAX;
        for(int i = 0; i < m; ++i) {
            result = min(result, dp[n - 1][i]);
        }
        return result;        
    }
};