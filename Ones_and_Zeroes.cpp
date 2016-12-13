class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int k = 0; k < strs.size(); k++) {

            int ones = 0, zeros = 0;
            for(int i = 0; i < (int)strs[k].length(); i++) {
                ones += (strs[k][i] == '1');
                zeros += (strs[k][i] == '0');
            }

            for(int i = n; i >= ones; i--) {
                for(int j = m; j >= zeros; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - ones][j - zeros] + 1);
                }
            }

        }

        return dp[n][m];
    }
};