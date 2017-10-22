// dp[i][j] = number of distinct sub-sequences for T[1...i] and S[1..j]
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; ++i) dp[i][0] = 0;
        for(int j = 0; j <= n; ++j) dp[0][j] = 1;
        for(int i = 1; i <= m; ++i) {
            for(int j = i; j <= n; ++j) {
                dp[i][j] = (t[i - 1] == s[j - 1]) ? dp[i - 1][j - 1] : 0;
                dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

// top-down
class Solution {
    int numDistinct(int i, string& s, int j, string& t, vector<vector<int>>& dp) {
        if(i == (int)s.length()) {
            return j == (int)t.length();
        }
        if(j == (int)t.length()) {
            return dp[i][j] = true;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ret = 0;
        if(t[j] == s[i]) {
            ret += numDistinct(i + 1, s, j + 1, t, dp);
        }
        ret += numDistinct(i + 1, s, j, t, dp);
        
        return dp[i][j] = ret;
    }
public:
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length();
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, -1));
        return numDistinct(0, s, 0, t, dp);
    }
};