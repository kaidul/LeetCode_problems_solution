class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid(int x, int y, int newX, int newY, vector<vector<int>>& matrix) {
        return (newX >= 0 and newY >= 0 and newX < matrix.size() and newY < matrix[0].size() and matrix[newX][newY] > matrix[x][y]);
    }
    
    int longestIncreasingPathUtil(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(dp[x][y] > 0) {
            return dp[x][y];
        }
        int maxLen = 0;
        for(int i = 0, n = sizeof(dx) / sizeof(dx[0]); i < n; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(isValid(x, y, newX, newY, matrix)) {
                maxLen = max(maxLen, longestIncreasingPathUtil(newX, newY, matrix, dp));
            }
        }
        return dp[x][y] = 1 + maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if(n == 0) {
            return 0;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxLen = INT_MIN;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                maxLen = max(maxLen, longestIncreasingPathUtil(i, j, matrix, dp));
            }
        }
        return maxLen;
    }
};