class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        const int n = (int)boxes.size();
        if(n == 0) return 0;
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0))); // MLE
        int dp[n + 1][n + 1][n + 1] = {0};
        for(int i = 0; i < n; i++) {
            for(int k = 1; k <= i; k++) {
                dp[i][i][k] = (k + 1) * (k + 1);
            }
        }
        
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                for(int k = 0; k <= i; k++) {
                    dp[i][j][k] = (k + 1) * (k + 1) + dp[i + 1][j][0];
                    for(int l = i + 1; l <= j; l++) {
                        if(boxes[i] == boxes[l]) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i + 1][l - 1][0] + dp[l][j][k + 1]);    
                        }
                    }
                }
            }
        }
        
        return dp[0][n - 1][0];
    }
};