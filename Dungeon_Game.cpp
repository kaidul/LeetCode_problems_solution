class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(m == 0) return 0;
        int n = dungeon[0].size();
        if(n == 0) return 0;
        /*
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[m - 1][n - 1] = max(1, -dungeon[m - 1][n - 1] + 1);
        
        for(int i = n - 2; i >= 0; --i) {
            dp[m - 1][i] = max(1, -dungeon[m - 1][i] + dp[m - 1][i + 1]);
        }
        
        for(int i = m - 2; i >= 0; --i) {
            dp[i][n - 1] = max(1, -dungeon[i][n - 1] + dp[i + 1][n - 1]);
        }
        
        for(int i = m - 2; i >= 0; --i) {
            for(int j = n - 2; j >= 0; --j) {
                dp[i][j] = max(1, -dungeon[i][j] + min(dp[i + 1][j], dp[i][j + 1]));
            }
        }
        
        return dp[0][0];
        */
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 1;
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                dp[j] = max(1, -dungeon[i][j] + ((j == n - 1) ? dp[j] : min(dp[j], dp[j + 1]))); 
            }
        }
        return dp[0];
    }
};