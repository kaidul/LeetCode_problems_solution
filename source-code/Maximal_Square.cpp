class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int result = 0;
        int m = matrix.size();
        if(m == 0) return result;
        int n = matrix[0].size();
        if(n == 0) return result;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; ++i) {
            dp[i][0] = (matrix[i][0] == '1') ? 1 : 0;
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        
        for(int i = 0; i < m; ++i) {
            // some prune applied
            // run the loop backward to converge earlier
            for(int j = n - 1; j >= 0; --j) {
                // if current result is greater than (dp[i][j] * dp[i][j])
                // there is no possibily to get larger value and expand this if branch
                if(dp[i][j] > 0 and result < (dp[i][j] * dp[i][j])) {
                    int lenX = 0, lenY = dp[i][j];
                    int squareLen = 0;
                    for(int k = i; k < m and dp[k][j] > 0; ++k) {
                        lenX++;
                        lenY = min(lenY, dp[k][j]);
                        int currSquareLen = min(lenX, lenY);
                        // if square length become smaller at some point,
                        // there is no way to found bigger value later
                        if(squareLen > currSquareLen) {
                            break;
                        }
                        squareLen = currSquareLen;
                        result = max(result, squareLen * squareLen);
                    }
                }
            }
        }
        return result;
    }
};