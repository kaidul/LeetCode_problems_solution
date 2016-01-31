class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        if(n == 0) return 0;
        
        vector <vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        for(int i = 1; i < m; ++i) dp[i][0] = (dp[i - 1][0] == 0 or obstacleGrid[i][0] == 1) ? 0 : 1;
        for(int i = 1; i < n; ++i) dp[0][i] = (dp[0][i - 1] == 0 or obstacleGrid[0][i] == 1) ? 0 : 1;
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};