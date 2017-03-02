class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = (int)s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                if(s[i] == s[j]) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};