class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = (int)word1.length();
        int m = (int)word2.length();
        // dp[i][j] = minimuum deletion required to make word1[0.. i] and word2[0.. j] same
        // base case: dp[i][0] = i for all i
        //            dp[0][j] = j for all j
        // dp[i][j] = dp[i - 1][j - 1] if word1[i - 1] == word2[j - 1]
        //          = 1 + min(dp[i - 1][j], dp[i][j - 1]) otherwise
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= m; j++) {
            dp[0][j] = j; 
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};