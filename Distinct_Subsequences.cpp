class Solution {
public:
    int numDistinct(string S, string T) {

        vector<int> f(T.length() + 1);

        f[T.length()] = 1;

        for(int i = S.length() - 1; i >= 0; --i) {
            for(int j = 0; j < T.length(); ++j) {
                f[j] += (S[i] == T[j]) * f[j + 1];
            }
        }
        return f[0];
    }
};

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