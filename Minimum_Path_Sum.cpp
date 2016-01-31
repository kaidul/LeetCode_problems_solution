class Solution {
public:
    /* Top-down DP - AC
    int minPathSum(int x, int y, vector<vector<int> > &grid, vector<vector<int> > &dp) {
        if(x == grid.size() - 1 and y == grid[0].size() - 1) return grid[x][y];
        if(x == grid.size() or y == grid[0].size()) return (1 << 30);
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = grid[x][y] + min(minPathSum(x + 1, y, grid, dp), minPathSum(x, y + 1, grid, dp));
    }

    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size() < 0) return 0;
        vector<vector<int> > dp(grid.size(), vector<int>(grid[0].size(), -1));
        return minPathSum(0, 0, grid, dp);
    }
    */

    // bottom-up DP- AC
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size() < 0) return 0;
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int> > dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        
        for(int i = 1; i < n; ++i) dp[0][i] = grid[0][i] + dp[0][i - 1];
        for(int i = 1; i < m; ++i) dp[i][0] = grid[i][0] + dp[i - 1][0];
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};