class Solution {
public:
    // Exhasutive search - TLE
    /*
    int uniquePathsUtils(int i, int j, int m, int n) {
        if(i == m - 1 and j == n - 1) {
            return 1;
        }
        int count = 0;
        if(j + 1 < n) {
            // visited[]
            count += uniquePathsUtils(i, j + 1, m, n);    
        }
        if(i + 1 < m) {
            count += uniquePathsUtils(i + 1, j, m, n);    
        }
        return count;
    }
    */

    int uniquePaths(int m, int n) {
        if(m == 0 or n == 0) return 0;
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }   
        return dp[m - 1][n - 1];
        
        // return uniquePathsUtils(0, 0, m, n);
    }
};