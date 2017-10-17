class Solution {
    int minCut(int i, int j, string const& s, vector<vector<int>>& dp) {
        if(i >= j) {
            return 0;
        }
        if(dp[i][j] != INT_MAX) {
            return dp[i][j];
        }
        if(s[i] == s[j] and minCut(i + 1, j - 1, s, dp) == 0) {
            return dp[i][j] = 0;
        }
        int Min = j - i;
        for(int k = i; k < j; k++) {
            Min = min(Min, 1 + minCut(i, k, s, dp) + minCut(k + 1, j, s, dp));
        }
        return dp[i][j] = Min;
    }
public:
    int minCut(string s) {
        // vector<vector<int>> dp(s.length(), vector<int>(s.length(), INT_MAX));
        // return minCut(0, s.length() - 1, s, dp);
        
        const int SIZE = s.length();
        vector<int> minCuts(SIZE + 1, 0);
        for (int i = 0; i <= SIZE; i++) {
            minCuts[i] = i - 1;
        }
        vector<vector<bool> > isPalFast(SIZE + 1, vector<bool>(SIZE + 1, false));

        for (int j = 2; j <= SIZE; j++) {
            for (int i = 1; i <= j; i++) {
                if (s[i - 1] == s[j - 1] and ((j - i) < 2 or isPalFast[i + 1][j - 1])) {
                    isPalFast[i][j] = true;
                    minCuts[j] = min(minCuts[j], minCuts[i - 1] + 1);
                }
            }
        }
        return minCuts[SIZE];
    }
};